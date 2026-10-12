#!/usr/bin/env bash
# Usage: run.sh <source.cpp|source.py>
#
# Testcase convention (same folder, same name as the source file):
#   <name>.in   -> fed to the program as stdin   (if missing, you type input in the terminal)
#   <name>.out  -> expected output               (if present, the result is diffed against it)

set -u

src="${1:?usage: run.sh <file.cpp|file.py>}"
dir="$(cd "$(dirname "$src")" && pwd)"
file="$(basename "$src")"
stem="${file%.*}"
ext="${file##*.}"

in_file="$dir/$stem.in"
out_file="$dir/$stem.out"
build_dir="$dir/build"
actual="$(mktemp)"
trap 'rm -f "$actual"' EXIT

case "$ext" in
  cpp|cc)
    mkdir -p "$build_dir"
    bin="$build_dir/$stem"
    echo "▶ compiling $file"
    g++ -std=c++17 -O2 -Wall -o "$bin" "$dir/$file" || { echo "✖ compile error"; exit 1; }
    cmd=("$bin")
    ;;
  py)
    cmd=(python3 "$dir/$file")
    ;;
  *)
    echo "unsupported file type: .$ext (use .cpp or .py)"; exit 1
    ;;
esac

if [[ ! -f "$in_file" ]]; then
  echo "▶ no $stem.in found — type input below (Ctrl-D to finish)"
  "${cmd[@]}"
  exit $?
fi

echo "▶ running with $stem.in"
"${cmd[@]}" < "$in_file" > "$actual"
status=$?
cat "$actual"
[[ $status -ne 0 ]] && { echo "✖ runtime error (exit code $status)"; exit $status; }

if [[ -f "$out_file" ]]; then
  # ignore trailing whitespace differences, as judges usually do
  if diff -q -B -b "$actual" "$out_file" > /dev/null; then
    echo "✔ PASSED — matches $stem.out"
  else
    echo "✖ WRONG ANSWER — diff (< yours, > expected):"
    diff -B -b "$actual" "$out_file"
    exit 1
  fi
fi

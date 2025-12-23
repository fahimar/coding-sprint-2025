using System;
using System.Collections.Generic;

public class Solution {
    public int MaxSubArray(int[] nums){
        int arraySum = nums[0];
        int total = 0;

        foreach (int i in nums) {
            if(total < 0) {
                total = 0;
            }

            total += i;

            arraySum = Math.Max(arraySum, total);
        }

        return arraySum;
    }
}

public class Program {
    public static void Main() {
        string input = Console.In.ReadToEnd();
        if (string.IsNullOrWhiteSpace(input)) return;

        List<int> values = new List<int>();
        int sign = 1;
        int num = 0;
        bool inNumber = false;

        for (int i = 0; i < input.Length; i++) {
            char c = input[i];

            if (c == '-' && !inNumber) {
                sign = -1;
                inNumber = true;
                num = 0;
                continue;
            }

            if (c >= '0' && c <= '9') {
                if (!inNumber) {
                    inNumber = true;
                    sign = 1;
                    num = 0;
                }
                num = (num * 10) + (c - '0');
            } else {
                if (inNumber) {
                    values.Add(sign * num);
                    inNumber = false;
                    sign = 1;
                    num = 0;
                }
            }
        }

        if (inNumber) values.Add(sign * num);
        if (values.Count == 0) return;

        int[] nums;
        int n = values[0];
        if (values.Count >= 2 && n >= 1 && values.Count == n + 1) {
            nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = values[i + 1];
        } else {
            nums = new int[values.Count];
            for (int i = 0; i < values.Count; i++) nums[i] = values[i];
        }

        int ans = new Solution().MaxSubArray(nums);
        Console.WriteLine(ans);
    }
}
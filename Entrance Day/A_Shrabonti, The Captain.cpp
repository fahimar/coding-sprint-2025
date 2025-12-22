#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long solve(string &K, long long N) {
    long long res = 0;
    for (char c : K) {
        long long digit = c - '0';
        
        res = res % N;                    
        res = ((res % N)*(10 % N)) % N; 
        res = (res + digit) % N;          
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N;
    string K;
    
    while (cin >> N >> K) {
        long long k_mod = solve(K, N);

        long long pos;
        if (k_mod == 0) {
            pos = N;
        } else {
            pos = k_mod;
        }

        if (pos == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
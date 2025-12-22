#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int rem = 0;   

    for(int i = 0; i < n; i++) {
        int runs;
        cin >> runs;

        if(runs < k) {
            rem++;
        }
    }

    cout << rem << '\n';

    return 0;
}

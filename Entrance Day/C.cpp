#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;          
        s.pop_back();    
        int c = stoi(s);  

        int m = 0;

        if (c < 60) {
            m += (60 - c) * 1;
            c = 60;
        }
        if (c < 80) {
            m += (80 - c) * 2;
            c = 80;
        }
        if (c < 100) {
            m += (100 - c) * 3;
        }

        cout << m << " minutes\n";
    }
    return 0;
}

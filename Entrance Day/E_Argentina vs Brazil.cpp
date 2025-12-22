#include <bits/stdc++.h>
using namespace std;

// helper: count goals ('1's) in a string
int countGoals(const string &s) {
    int c = 0;
    for (char ch : s) if (ch == '1') c++;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;
    // multiple test cases until EOF
    while (cin >> A >> B) {

        // Full-time result
        if (A > B) {
            cout << "Argentina\n";
            continue;
        }
        if (A < B) {
            cout << "Brazil\n";
            continue;
        }

        // Draw → go to penalties
        string sA, sB;
        if (!(cin >> sA >> sB)) break;  // safety

        int gA = countGoals(sA);
        int gB = countGoals(sB);

        if (gA > gB) {
            cout << "Argentina\n";
            continue;
        }
        if (gA < gB) {
            cout << "Brazil\n";
            continue;
        }

        // Still tied → repeat K-shot penalty rounds until someone wins
        string sdA, sdB;
        while (cin >> sdA >> sdB) {   // read next K-shot round
            int a = countGoals(sdA);
            int b = countGoals(sdB);

            if (a > b) {
                cout << "Argentina\n";
                break;
            }
            if (a < b) {
                cout << "Brazil\n";
                break;
            }
            // if equal, loop again and read another pair
        }
    }
    return 0;
}

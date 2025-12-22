#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // Upper part (N-1 lines)
    for (int i = 1; i < N; i++) {
        // Print spaces
        for (int j = 0; j < N - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    // Middle part (2 lines of 2*N stars)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2 * N; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    // Lower part (N-1 lines, reverse of upper)
    for (int i = N - 1; i >= 1; i--) {
        // Print spaces
        for (int j = 0; j < N - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int j = 0; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    return 0;
}
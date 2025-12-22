#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;

    while (cin >> N >> K) {
        // Calculate final position after counting K times in a circle
        // Since we start at position 1 and count K times
        // The final position is: K % N (with special handling for when K % N == 0)
        long long finalPosition = K % N;

        // If K % N == 0, we're at position N (the last person)
        // Otherwise we're at position K % N
        if (finalPosition == 0) {
            finalPosition = N;
        }

        if (finalPosition == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}

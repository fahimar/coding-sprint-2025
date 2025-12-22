#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int Y;
    cin >> Y;
    
    if (Y == 1) {
        cout << 1 << endl;
    } else {
        // Sum = 2^(2Y-3)
        long long result = (1LL << (2 * Y - 3));
        cout << result << endl;
    }
    
    return 0;
}
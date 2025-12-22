#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        
        vector<int> groups;
        
        // Count consecutive 1s
        for (int i = 0; i < s.length(); ) {
            if (s[i] == '1') {
                int count = 0;
                while (i < s.length() && s[i] == '1') {
                    count++;
                    i++;
                }
                groups.push_back(count);
            } else {
                i++;
            }
        }
        
        // Sort descending (largest first)
        sort(groups.begin(), groups.end(), greater<int>());
        
        // Zaza takes odd positions (0-indexed: 0, 2, 4...)
        int result = 0;
        for (int i = 0; i < groups.size(); i += 2) {
            result += groups[i];
        }
        
        cout << result << "\n";
    }
    
    return 0;
}
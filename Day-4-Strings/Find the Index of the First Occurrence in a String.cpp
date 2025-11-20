#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if(m == 0) return 0;

        for (int i = 0; i <= n-m; i++)
        {
            int j = 0;
            while(j<m && haystack[i+j]==needle[j]) {
                j++;
            }
            if(j==m) return i;
        }

        return -1;
        
    }
};

int main() {
    Solution solution;
    string haystack, needle;
    
    cout << "Enter haystack string: ";
    cin >> haystack;
    
    cout << "Enter needle string: ";
    cin >> needle;
    
    int result = solution.strStr(haystack, needle);
    
    cout << "Output: " << result << endl;
    
    return 0;
}
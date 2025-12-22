class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int left = 0, maxLength = 0, len = s.length();

        for (int r = 0; r < len; r++)
        {
            if (lastSeen[s[r]] >= left)
            {
                left = lastSeen[s[r]] + 1;  
            }
            lastSeen[s[r]] = r;
            maxLength = max(maxLength, r - left + 1);
            
        }
        
        return maxLength;
    }
};
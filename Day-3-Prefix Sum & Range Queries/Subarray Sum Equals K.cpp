class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;


        int curr =0, count =0;

        for(int x : nums) {
            curr += x;

            if(freq.find(curr - k) != freq.end()) {
                count += freq[curr - k];
            }

            freq[curr]++;

        }
        return count;
    }
};
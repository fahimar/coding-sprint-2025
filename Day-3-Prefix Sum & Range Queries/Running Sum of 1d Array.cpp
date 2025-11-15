class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int len = nums.size();
       for (int i = 1; i <= len-1; i++)
       {
            nums[i] += nums[i-1]
       }

       return nums;
        
    }
};
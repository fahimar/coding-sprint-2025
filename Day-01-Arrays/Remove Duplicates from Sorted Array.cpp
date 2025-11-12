class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int ind=1,j=1;
            if(nums.empty()) return 0;
            for( ; j<nums.size();++j) {
                if(nums[j]!= nums[ind-1])
                {
                    nums[ind] = nums[j];
                    ind += 1;
                }
            }
            return ind;
        }

};
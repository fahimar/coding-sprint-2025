class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int insertPos = 0;
        for(int x : nums){
            if(x!=0){
                nums[insertPos++] = x;
            }
        }

        while (insertPos<len)
        {
            nums[insertPos++] = 0;
        }
        
    }
};
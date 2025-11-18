class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int arraySum = nums[0];

        int total = 0;

        for(int i : nums) {
            if(total < 0) {total=0;}
            total += i;
            arraySum = max(arraySum,total);

        }

        return total;
    }
    
};

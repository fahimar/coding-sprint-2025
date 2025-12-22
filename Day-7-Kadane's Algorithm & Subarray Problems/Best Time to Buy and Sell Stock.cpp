class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int buyPrice = prices[0];
            int maxProf = 0;
            for(int i=1;i<prices.size();i++){
                if(prices[i]<buyPrice) {
                    buyPrice = prices[i];
                }
                maxProf = max(maxProf,(prices[i]-buyPrice));
            }

            return maxProf;
        };
}
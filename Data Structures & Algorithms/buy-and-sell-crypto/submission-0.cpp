class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minBuyingPrice = INT_MAX;
        for(int i=0;i<prices.size();i++) {
            minBuyingPrice = min(minBuyingPrice, prices[i]);
            profit = max(profit, prices[i]-minBuyingPrice);
        }
        return profit;
    }
};

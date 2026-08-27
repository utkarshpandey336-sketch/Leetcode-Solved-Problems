class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy = INT_MAX;
        int profit = 0;

        for(int i = 0; i < prices.size(); i++) {

            // Minimum price seen so far
            buy = min(buy, prices[i]);

            // Profit if we sell today
            profit = max(profit, prices[i] - buy);
        }

        return profit;
    }
};
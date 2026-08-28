class Solution {
public:
    int solve(int i, int buy, vector<int>& prices,
              vector<vector<int>>& dp,int fee) {

        // No days left
        if(i >= prices.size()) {
            return 0;
        }

        // Already calculated
        if(dp[i][buy] != -1) {
            return dp[i][buy];
        }

        if(buy == 1) {

            // Buy OR don't buy
            return dp[i][buy] = max(
                -prices[i] + solve(i + 1, 0, prices, dp,fee),
                solve(i + 1, 1, prices, dp,fee)
            );
        }

        else {

            // Sell OR don't sell
            return dp[i][buy] = max(
                prices[i] - fee+solve(i + 1, 1, prices, dp,fee),
                solve(i + 1, 0, prices, dp,fee)
            );
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return solve(0, 1, prices, dp,fee);
    }
};
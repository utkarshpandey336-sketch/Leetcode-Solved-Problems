class Solution {
public:

    int solve(int i, int buy, vector<int>& prices,
              vector<vector<int>>& dp) {

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
                -prices[i] + solve(i + 1, 0, prices, dp),
                solve(i + 1, 1, prices, dp)
            );
        }

        else {

            // Sell OR don't sell
            return dp[i][buy] = max(
                prices[i] + solve(i + 2, 1, prices, dp),
                solve(i + 1, 0, prices, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return solve(0, 1, prices, dp);
    }
};
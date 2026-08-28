class Solution {
public:

    int solve(int i, int buy, vector<int>& prices,
              vector<vector<vector<int>>>& dp,
              int transaction) {

        // No days left
        if(i == prices.size()) {
            return 0;
        }

        // Already completed 2 transactions
        if(transaction == 2) {
            return 0;
        }

        // Already calculated
        if(dp[i][buy][transaction] != -1) {
            return dp[i][buy][transaction];
        }

        if(buy == 1) {

            // Buy OR don't buy
            return dp[i][buy][transaction] = max(
                -prices[i] + solve(
                    i + 1, 0, prices, dp, transaction
                ),

                solve(
                    i + 1, 1, prices, dp, transaction
                )
            );
        }

        else {

            // Sell OR don't sell
            return dp[i][buy][transaction] = max(
                prices[i] + solve(
                    i + 1, 1, prices, dp, transaction + 1
                ),

                solve(
                    i + 1, 0, prices, dp, transaction
                )
            );
        }
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        return solve(0, 1, prices, dp, 0);
    }
};
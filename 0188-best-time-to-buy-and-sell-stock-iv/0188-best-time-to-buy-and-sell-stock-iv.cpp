class Solution {
public:
    int solve(int i, int buy, vector<int>& prices,
              vector<vector<vector<int>>>& dp,
              int k) {

        // No days left
        if(i == prices.size()) {
            return 0;
        }

        // Already completed 2 transactions
        if(k<= 0) {
            return 0;
        }

        // Already calculated
        if(dp[i][buy][k] != -1) {
            return dp[i][buy][k];
        }

        if(buy == 1) {

            // Buy OR don't buy
            return dp[i][buy][k] = max(
                -prices[i] + solve(
                    i + 1, 0, prices, dp, k
                ),

                solve(
                    i + 1, 1, prices, dp, k
                )
            );
        }

        else {

            // Sell OR don't sell
            return dp[i][buy][k] = max(
                prices[i] + solve(
                    i + 1, 1, prices, dp, k- 1
                ),

                solve(
                    i + 1, 0, prices, dp, k
                )
            );
        }
    }
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k+1, -1))
        );

        return solve(0, 1, prices, dp, k);
    }
};
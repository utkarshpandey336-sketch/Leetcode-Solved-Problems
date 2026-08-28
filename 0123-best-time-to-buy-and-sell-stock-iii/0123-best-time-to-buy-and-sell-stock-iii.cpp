class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, 0))
        );

        for(int i = n - 1; i >= 0; i--) {

            for(int transaction = 0; transaction < 2; transaction++) {

                // Can buy
                dp[i][1][transaction] = max(
                    -prices[i] + dp[i + 1][0][transaction],
                    dp[i + 1][1][transaction]
                );

                // Holding stock → can sell
                dp[i][0][transaction] = max(
                    prices[i] + dp[i + 1][1][transaction + 1],
                    dp[i + 1][0][transaction]
                );
            }
        }

        return dp[0][1][0];
    }
};
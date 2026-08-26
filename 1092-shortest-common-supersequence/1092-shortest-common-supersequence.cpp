class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
         int n = str1.size();
        int m = str2.size();

        // LCS DP
        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(str1[i - 1] == str2[j - 1]) {

                    dp[i][j] = 1 + dp[i - 1][j - 1];

                }
                else {

                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i][j - 1]
                    );
                }
            }
        }
        // Build the shortest common supersequence
        string ans = "";

        int i = n;
        int j = m;

        while(i > 0 && j > 0) {

            // Same character → take it once
            if(str1[i - 1] == str2[j - 1]) {

                ans += str1[i - 1];

                i--;
                j--;
            }

            // Take character from str1
            else if(dp[i - 1][j] > dp[i][j - 1]) {

                ans += str1[i - 1];

                i--;
            }

            // Take character from str2
            else {

                ans += str2[j - 1];

                j--;
            }
        }
               // Remaining characters
        while(i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while(j > 0) {
            ans += str2[j - 1];
            j--;
        }

        // We constructed it backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
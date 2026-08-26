class Solution {
public:

    int solve(int i, int j, string& word1, string& word2,
              vector<vector<int>>& dp) {

        // word1 is finished
        if(i < 0) {
            return j + 1;
        }

        // word2 is finished
        if(j < 0) {
            return i + 1;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters are same
        if(word1[i] == word2[j]) {

            return dp[i][j] =
                solve(i - 1, j - 1, word1, word2, dp);
        }

        // Characters are different
        else {

            int deleteChar =
                solve(i - 1, j, word1, word2, dp);

            int insertChar =
                solve(i, j - 1, word1, word2, dp);

            int replaceChar =
                solve(i - 1, j - 1, word1, word2, dp);

            return dp[i][j] =
                1 + min({
                    deleteChar,
                    insertChar,
                    replaceChar
                });
        }
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return solve(
            n - 1,
            m - 1,
            word1,
            word2,
            dp
        );
    }
};
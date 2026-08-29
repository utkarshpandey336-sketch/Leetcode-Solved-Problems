class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> parent(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int lastIndex = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[i] % nums[j] == 0 &&
                   dp[j] + 1 > dp[i]) {

                    dp[i] = dp[j] + 1;

                    parent[i] = j;
                }
            }

            if(dp[i] > dp[lastIndex]) {
                lastIndex = i;
            }
        }

        // Reconstruct the subset
        vector<int> answer;

        while(parent[lastIndex] != lastIndex) {

            answer.push_back(nums[lastIndex]);

            lastIndex = parent[lastIndex];
        }

        answer.push_back(nums[lastIndex]);

        reverse(answer.begin(), answer.end());

        return answer;
    }
};
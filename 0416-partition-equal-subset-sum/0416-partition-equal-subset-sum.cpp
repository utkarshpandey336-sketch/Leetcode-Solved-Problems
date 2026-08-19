class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int n = nums.size();

        // 1. Calculate total sum
        int sum = 0;
        for(int x : nums) {
            sum += x;
        }

        // 2. Odd sum cannot be divided equally
        if(sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<vector<bool>> dp(
            n,
            vector<bool>(target + 1, false)
        );
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                 bool notTake = dp[i-1][t];
                 bool take=false;
                 if(nums[i]<=t){
                    take=dp[i-1][t-nums[i]];
                 }
                 dp[i][t]=take||notTake;
            }
        }
        return dp[n-1][target];
    }
};
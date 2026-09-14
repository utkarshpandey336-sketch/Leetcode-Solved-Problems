class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        long long k = sum % p;

        if (k == 0)
            return 0;

        int ans = INT_MAX;

        unordered_map<long long, int> mp;
        mp[0] = -1;

        long long a = 0;

        for (int i = 0; i < nums.size(); i++) {
            a += nums[i];

            long long rem = a % p;

            long long needed = (rem - k + p) % p;

            if (mp.count(needed)) {
                ans = min(ans, i - mp[needed]);
            }

            mp[rem] = i;
        }

        if (ans == INT_MAX || ans == nums.size())
            return -1;

        return ans;
    }
};
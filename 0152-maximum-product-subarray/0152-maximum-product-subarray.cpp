class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int tempMax = maxProduct;
            int tempMin = minProduct;

            maxProduct = max({x, x * tempMax, x * tempMin});
            minProduct = min({x, x * tempMax, x * tempMin});

            ans = max(ans, maxProduct);
        }

        return ans;
    }
};

class Solution {
public:

    int findSum(vector<int>& nums, int divisor) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + divisor - 1) / divisor;   // Ceiling division
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low = 1;

        int high = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            high = max(high, nums[i]);
        }

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int sum = findSum(nums, mid);

            if (sum <= threshold) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
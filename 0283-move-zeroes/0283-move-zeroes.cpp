class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;

        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] != 0) {
                nums[left] = nums[right];
                left++;
            }
        }

        for(int i = left; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
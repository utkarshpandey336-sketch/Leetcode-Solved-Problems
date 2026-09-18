class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == c1) {
                cnt1++;
            }
            else if(nums[i] == c2) {
                cnt2++;
            }
            else if(cnt1 == 0) {
                c1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0) {
                c2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        int f1 = 0, f2 = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == c1) f1++;
            if(nums[i] == c2) f2++;
        }

        vector<int> ans;

        if(f1 > nums.size() / 3)
            ans.push_back(c1);

        if(f2 > nums.size() / 3 && c2 != c1)
            ans.push_back(c2);

        return ans;
    }
};
class Solution {
public:
    void print(int index,vector<int>& ds,vector<int>& nums,    vector<vector<int>>& ans){
        if(index==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        print(index+1,ds,nums,ans);
        ds.pop_back();
        print(index+1,ds,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>> ans;
        print(0,ds,nums,ans);
        return ans;
    }
};
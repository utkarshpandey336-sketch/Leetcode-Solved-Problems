class Solution {
public:
    void solve(int index, vector<int>& candidates,
               int target, vector<int>& ds,
               vector<vector<int>>& ans)
    {
        // Found a valid combination
        if(target == 0)
        {
            ans.push_back(ds);
            return;
        }

        // No more elements or target became negative
        if(index == candidates.size() || target < 0)
        {
            return;
        }

        // Pick
        ds.push_back(candidates[index]);

        // Same index because we can pick the element again
        solve(index, candidates,
              target - candidates[index], ds, ans);

        ds.pop_back();

        // Don't Pick
        solve(index + 1, candidates,
              target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, candidates, target, ds, ans);

        return ans;
    }
};
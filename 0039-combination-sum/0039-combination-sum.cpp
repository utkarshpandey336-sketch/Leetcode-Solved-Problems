class Solution {
public:
    void solve(int index, vector<int>& candidates, int target,
               vector<int>& ds, vector<vector<int>>& ans)
    {
        if(index == candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        // Pick
        if(candidates[index] <= target)
        {
            ds.push_back(candidates[index]);

            // Same index because we can pick it again
            solve(index, candidates, target - candidates[index], ds, ans);

            ds.pop_back();
        }

        // Don't Pick
        solve(index + 1, candidates, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(0, candidates, target, ds, ans);

        return ans;
    }
};
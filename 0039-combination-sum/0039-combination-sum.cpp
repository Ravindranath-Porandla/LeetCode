class Solution {
public:
    void solve(int idx, int n, vector<int>& ds, int target,
               vector<int>& candidates, vector<vector<int>>& ans) {
        if (idx == n) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // pick
        if (target >= candidates[idx]) {
            ds.push_back(candidates[idx]);
            solve(idx, n, ds, target - candidates[idx], candidates, ans);
            ds.pop_back();
        }

        // not pick
        solve(idx + 1, n, ds, target, candidates, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        solve(0, n, ds, target, candidates, ans);

        return ans;
    }
};
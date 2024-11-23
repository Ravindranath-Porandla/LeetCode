class Solution {
public:
    void solve(vector<bool>& mark, vector<int>& ds, vector<int>& nums,
               vector<vector<int>>& ans) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!mark[i]) {
                mark[i] = true;
                ds.push_back(nums[i]);
                solve(mark, ds, nums, ans);
                ds.pop_back();
                mark[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> mark(n, false);
        vector<int> ds;
        vector<vector<int>> ans;
        solve(mark, ds, nums, ans);
        return ans;
    }
};
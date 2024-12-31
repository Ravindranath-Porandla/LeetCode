class Solution {
public:
    void solve(int idx, vector<int>& ds, vector<vector<int>>& ans, int k, int n){
        if(k == 0){
            if(n == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(idx > 9)
            return;
        
        ds.push_back(idx);
        solve(idx + 1, ds, ans, k - 1, n - idx);
        ds.pop_back();

        solve(idx + 1, ds, ans, k, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, ds, ans, k, n);
        return ans;
    }
};
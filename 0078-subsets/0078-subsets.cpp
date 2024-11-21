class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(ds);
            return;
        }

        //pick
        ds.push_back(nums[idx]);
        solve(idx + 1, nums, ds, ans);
        ds.pop_back();

        //not_pick
        solve(idx + 1, nums, ds, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;
        solve(0, nums, ds, ans);
        return ans;
    }
};
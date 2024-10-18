class Solution {
public:
    void solve(int idx, vector<int>& nums, vector<int>& ds,
               vector<vector<int>>& subsets) {
        if (idx == nums.size()) {
            subsets.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        solve(idx + 1, nums, ds, subsets);
        ds.pop_back();

        solve(idx + 1, nums, ds, subsets);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> ds;
        solve(0, nums, ds, subsets);
        map<int, int> mp;
        for (vector<int> it : subsets) {
            int x = 0;
            for (int n : it) {
                x = x | n;
            }
            mp[x]++;
        }
        auto last = mp.rbegin();
        return last->second;
    }
};
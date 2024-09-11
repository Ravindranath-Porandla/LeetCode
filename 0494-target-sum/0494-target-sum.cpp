class Solution {
public:
    int solve(int idx, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;
            if (target == 0 || target == nums[0])
                return 1;
            return 0;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int not_pick = solve(idx - 1, nums, target, dp);
        int pick = 0;
        if (nums[idx] <= target)
            pick = solve(idx - 1, nums, target - nums[idx], dp);

        return dp[idx][target] = pick + not_pick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        int n = nums.size();
        for (int num : nums)
            total_sum += num;
        if ((total_sum - target) < 0 || (total_sum - target) % 2 != 0)
            return 0;
        int req = (total_sum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(req + 1, -1));
        int ans = solve(n - 1, nums, req, dp);
        return ans;
    }
};
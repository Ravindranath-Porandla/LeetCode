class Solution {
public:
    int solve(int idx, vector<int>& nums, int target, vector<vector<int>>& dp,
              int total_sum) {
        if (idx == 0) {
            if (target == nums[0] && target == -nums[0])
                return 2;
            return (target == nums[0]) || (target == -nums[0]);
        }

        if ((target + total_sum < 0) ||
            (target + total_sum >= 2 * total_sum + 1))
            return 0;

        if (dp[idx][target + total_sum] != -1) {
            return dp[idx][target + total_sum];
        }

        int plus = solve(idx - 1, nums, target - nums[idx], dp, total_sum);
        int minus = solve(idx - 1, nums, target + nums[idx], dp, total_sum);

        return dp[idx][target + total_sum] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        // If target is out of the possible sum range, return 0
        if (abs(target) > total_sum)
            return 0;

        // Memoization Table (Shift index by `total_sum` to handle negative
        // targets)
        vector<vector<int>> dp(n, vector<int>(2 * total_sum + 1, -1));

        return solve(n - 1, nums, target, dp, total_sum);
    }
};

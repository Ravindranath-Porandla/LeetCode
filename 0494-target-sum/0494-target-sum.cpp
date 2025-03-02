class Solution {
public:
    // int solve(int idx, vector<int>& nums, int target, vector<vector<int>>&
    // dp,
    //           int total_sum) {
    //     if (idx == 0) {
    //         if (target == nums[0] && target == -nums[0])
    //             return 2;
    //         return (target == nums[0]) || (target == -nums[0]);
    //     }

    //     if ((target + total_sum < 0) ||
    //         (target + total_sum >= 2 * total_sum + 1))
    //         return 0;

    //     if (dp[idx][target + total_sum] != -1) {
    //         return dp[idx][target + total_sum];
    //     }

    //     int plus = solve(idx - 1, nums, target - nums[idx], dp, total_sum);
    //     int minus = solve(idx - 1, nums, target + nums[idx], dp, total_sum);

    //     return dp[idx][target + total_sum] = plus + minus;
    // }

    int findTargetSumWays(vector<int>& nums, int t) {
        int n = nums.size();
        int total_sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(t) > total_sum)
            return 0;

        vector<vector<int>> dp(2, vector<int>(2 * total_sum + 1, 0));

        // return solve(n - 1, nums, target, dp, total_sum);

        for (int target = -total_sum; target <= total_sum; target++) {
            if (target == nums[0] && target == -nums[0])
                dp[0][target + total_sum] = 2;
            else if ((target == nums[0]) || (target == -nums[0])) {
                dp[0][target + total_sum] = 1;
            }
        }

        for (int idx = 1; idx < n; idx++) {
            for (int target = -total_sum; target <= total_sum; target++) {
                int plus = 0, minus = 0;

                if ((target - nums[idx]) + total_sum >= 0 &&
                    (target - nums[idx]) + total_sum < 2 * total_sum + 1)
                    plus = dp[(idx - 1) % 2][(target - nums[idx]) + total_sum];

                if ((target + nums[idx]) + total_sum >= 0 &&
                    (target + nums[idx]) + total_sum < 2 * total_sum + 1)
                    minus = dp[(idx - 1) % 2][(target + nums[idx]) + total_sum];

                dp[idx % 2][target + total_sum] = plus + minus;
            }
        }

        return dp[(n - 1) % 2][t + total_sum];
    }
};

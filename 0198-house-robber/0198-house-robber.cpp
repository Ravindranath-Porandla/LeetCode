class Solution {
public:
    // int solve(int idx, vector<int>& nums, vector<int>& dp) {
    //     if (idx == 0)
    //         return nums[0];
    //     if (idx < 0)
    //         return 0;

    //     if (dp[idx] != -1)
    //         return dp[idx];
    //     int rob = nums[idx] + solve(idx - 2, nums, dp);
    //     int not_rob = solve(idx - 1, nums, dp);

    //     return dp[idx] = max(rob, not_rob);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(2, -1);

        dp[0] = nums[0];
        for (int idx = 1; idx < n; idx++) {
            int rob = nums[idx];
            if (idx > 1)
                rob += dp[(idx - 2) % 2];
            int not_rob = dp[(idx - 1) % 2];

            dp[idx % 2] = max(rob, not_rob);
        }
        // int ans = solve(n - 1, nums, dp);
        // return ans;
        return dp[(n - 1) % 2];
    }
};
class Solution {
public:
    // int solve(int currIdx, int prevIdx, vector<int>& nums,
    //           vector<vector<int>>& dp) {
    //     if (currIdx == 0) {
    //         return (prevIdx == nums.size() || nums[currIdx] < nums[prevIdx]);
    //     }

    //     if (dp[currIdx][prevIdx] != -1) {
    //         return dp[currIdx][prevIdx];
    //     }

    //     int pick = 0;
    //     if (prevIdx == nums.size() || nums[prevIdx] > nums[currIdx]) {
    //         pick = 1 + solve(currIdx - 1, currIdx, nums, dp);
    //     }

    //     int not_pick = solve(currIdx - 1, prevIdx, nums, dp);

    //     return dp[currIdx][prevIdx] = max(pick, not_pick);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        //return solve(n - 1, n, nums, dp);

        for (int prevIdx = 0; prevIdx <= n; prevIdx++) {
            dp[0][prevIdx] =
                (prevIdx == nums.size() || nums[0] < nums[prevIdx]);
        }

        for (int currIdx = 1; currIdx < n; currIdx++) {
            for (int prevIdx = 0; prevIdx <= n; prevIdx++) {
                int pick = 0;
                if (prevIdx == nums.size() || nums[prevIdx] > nums[currIdx]) {
                    pick = 1 + dp[currIdx - 1][currIdx];
                }

                int not_pick = dp[currIdx - 1][prevIdx];

                dp[currIdx][prevIdx] = max(pick, not_pick);
            }
        }

        return dp[n - 1][n];
    }
};
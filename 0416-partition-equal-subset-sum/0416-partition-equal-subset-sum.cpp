class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        if(nums.size() == 1)    return false;
        for (int num : nums) {
            sum += num;
        }
        if (sum & 1)
            return false;
        int n = nums.size();
        int t = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(t + 1, false));

        for (int idx = 0; idx < n; idx++) {
            dp[idx][0] = true;
        }

        // dp[0][nums[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= t; target++) {
                bool not_pick = dp[idx - 1][target];
                bool pick = false;
                if (target >= nums[idx]) {
                    pick = dp[idx - 1][target - nums[idx]];
                }

                dp[idx][target] = pick || not_pick;
            }
        }
        return dp[n - 1][t];
    }
};

class Solution {
public:
    int solve(int idx, int can_rob, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == 0){
            if(can_rob){
                return nums[0];
            } else {
                return 0;
            }
        }

        if(dp[idx][can_rob] != -1)
            return dp[idx][can_rob];

        int profit = INT_MIN;

        if(can_rob){
            profit = max(nums[idx] + solve(idx - 1, 0, nums, dp), 
                            solve(idx - 1, 1, nums, dp));
        } else {
            profit = solve(idx - 1, 1, nums, dp);
        }

        return dp[idx][can_rob] = profit;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(n - 1, 1, nums, dp);
    }
};
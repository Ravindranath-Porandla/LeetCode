class Solution {
public:
    int solve(int idx, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (idx == 0) {
            return (nums[0] == target);
        }

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        int pick = 0;
        if (target >= nums[idx]) {
            pick = solve(idx - 1, nums, target - nums[idx], dp);
        }

        int not_pick = solve(idx - 1, nums, target, dp);

        return dp[idx][target] = (pick || not_pick);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>((sum / 2) + 1, -1));

        if (sum % 2 != 0) {
            return 0;
        }

        

        return solve(nums.size() - 1, nums, sum / 2, dp);
    }
};
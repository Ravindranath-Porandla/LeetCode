class Solution {
public:
    // bool solve(int idx, int target, vector<int>& nums) {
    //     if (target == 0)
    //         return true;
    //     if (idx == 0)
    //         return nums[0] == target;

    //     bool pick = solve(idx - 1, target - nums[idx], nums);
    //     bool not_pick = solve(idx - 1, target, nums);

    //     return pick || not_pick;
    // }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 == 1)
            return false;
        int tar = sum / 2;

        vector<vector<bool>> dp(2, vector<bool>(tar + 1, false));

        // bool ans = solve(n - 1, target, nums);
        // return ans;
        for (int idx = 0; idx < n; idx++)
            dp[idx % 2][0] = true;
        //dp[0][nums[0]] = true;

        for (int idx = 1; idx < n; idx++) {
            for (int target = 1; target <= tar; target++) {
                bool pick = false;
                if (target >= nums[idx])
                    pick = dp[(idx - 1) % 2][target - nums[idx]];
                bool not_pick = dp[(idx - 1) % 2][target];

                dp[idx % 2][target] = pick || not_pick;
            }
        }
        return dp[(n - 1) % 2][tar];
    }
};
class Solution {
public:
    // int solve(int idx, vector<int>& nums){
    //     if(idx == 0){
    //         return nums[0];
    //     }

    //     if(idx == 1){
    //         return max(nums[0], nums[1]);
    //     }

    //     int rob = nums[idx] + solve(idx - 2, nums);
    //     int dont_rob = solve(idx - 1, nums);

    //     return max(rob, dont_rob);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        vector<int> dp(2, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int idx = 2; idx < n; idx++) {
            int rob = nums[idx] + dp[(idx - 2) % 2];
            int dont_rob = dp[(idx - 1) % 2];

            dp[idx % 2] = max(rob, dont_rob);
        }
        // return solve(n - 1, nums);
        return dp[(n - 1) % 2];
    }
};
class Solution {
public:
    // int solve(int idx, vector<int>& nums){
    //     if(idx == 0)
    //         return nums[0];
    //     if(idx < 0)
    //         return 0;

    //     int rob = nums[idx] + solve(idx - 2, nums);
    //     int cannot_rob = solve(idx - 1, nums);

    //     return max(rob, cannot_rob);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(2, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int idx = 2; idx <= n; idx++){
            int rob = nums[idx - 1] + dp[(idx - 2) % 2];
            int cannot_rob = dp[(idx - 1) % 2];

            dp[idx % 2] = max(rob, cannot_rob);
        }
        //return solve(n - 1, nums);

        return dp[n % 2];
    }
};
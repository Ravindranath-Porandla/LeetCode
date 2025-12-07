class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(2, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int idx = 2; idx <= n; idx++) {
            int one_step = dp[(idx - 1) % 2];
            int two_step = dp[(idx - 2) % 2];

            dp[idx % 2] = one_step + two_step;
        }
        return dp[n % 2];
    }
};
class Solution {
public:
    int solve(int n, vector<int>& cost) {
        vector<int> dp(2, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int idx = 2; idx < n; idx++) {
            int one_step = cost[idx] + dp[(idx - 1) % 2];
            int two_step = cost[idx] + dp[(idx - 2) % 2];

            dp[idx % 2] = min(one_step, two_step);
        }

        return min(dp[(n - 1) % 2], dp[(n - 2) % 2]); 
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(n, cost); 
    }
};

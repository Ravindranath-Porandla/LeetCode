class Solution {
public:
    int climbStairs(int n) {
        // if(n <= 1)
        //     return 1;
        
        // return climbStairs(n - 1) + climbStairs(n - 2);

        // vector<int> dp(n + 1);
        // dp[0] = 1;
        // dp[1] = 1;
        int prev2 = 1;
        int prev1 = 1;

        for(int i = 2; i <= n; i++){
           // dp[i % 2] = dp[(i - 1) % 2] + dp[(i - 2) % 2];
           int curri = prev1 + prev2;
           prev2 = prev1;
           prev1 = curri;
        }

        //return dp[n % 2];
        return prev1;
    }
};
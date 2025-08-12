class Solution {
public:
    const int MOD = 1e9 + 7;

    int intPow(int base, int exp) {
        int res = 1;
        for (int k = 0; k < exp; k++) {
            res *= base;
        }
        return res;
    }

    int solve(int n, int x, int i, vector<vector<int>> &dp) {
        if (n == 0) return 1; // found one way
        if (n < 0) return 0;  // overshoot
        if (i > n) return 0;  // no more numbers to pick

        if (dp[n][i] != -1) return dp[n][i];

        int val = intPow(i, x);
        if (val > n) return dp[n][i] = 0; // can't use i

        // pick i
        int pick = solve(n - val, x, i + 1, dp) % MOD;
        // skip i
        int notPick = solve(n, x, i + 1, dp) % MOD;

        return dp[n][i] = (pick + notPick) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, x, 1, dp);
    }
};

class Solution {
public:
    // int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
    //     if (i == 0 && j == 0)
    //         return 1;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int left = 0;
    //     if (j - 1 >= 0)
    //         left = solve(i, j - 1, m, n, dp);
    //     int up = 0;
    //     if (i - 1 >= 0)
    //         up = solve(i - 1, j, m, n, dp);

    //     return dp[i][j] = left + up;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n, 0));
        // return solve(m - 1, n - 1, m , n, dp);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i == 0 && j == 0){
                    dp[0][0] = 1;
                    continue;
                }
                int left = 0;
                if (j - 1 >= 0)
                    left = dp[i % 2][j - 1];
                int up = 0;
                if (i - 1 >= 0)
                    up = dp[(i - 1) % 2][j];

                dp[i % 2][j] = left + up;
            }
        }

        return dp[(m - 1) % 2][n - 1];
    }
};
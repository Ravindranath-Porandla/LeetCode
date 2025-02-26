class Solution {
public:
    // int solve(int row, int col, int m, int n, vector<vector<int>>& dp) {
    //     if (row == 0 && col == 0)
    //         return 1;
    //     if (row < 0 || row >= m || col < 0 || col >= n)
    //         return 0;

    //     if (dp[row][col] != -1)
    //         return dp[row][col];
    //     int up = solve(row - 1, col, m, n, dp);
    //     int left = solve(row, col - 1, m, n, dp);

    //     return dp[row][col] = up + left;
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(2, vector<int>(n, 1));
        // int ans = solve(m - 1, n - 1, m, n, dp);
        // return ans;

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++) {
                int up = dp[(row - 1) % 2][col];
                int left = dp[row % 2][col - 1];

                dp[row % 2][col] = up + left;
            }
        }

        return dp[(m - 1) % 2][n - 1];
    }
};
class Solution {
public:
    // int solve(int row, int col, int m, int n, vector<vector<int>>& grid) {
    //     if (row == 0 && col == 0)
    //         return grid[row][col];
    //     if (row < 0 || col < 0)
    //         return 1e9;

    //     int up = grid[row][col] + solve(row - 1, col, m, n, grid);
    //     int left = grid[row][col] + solve(row, col - 1, m, n, grid);

    //     return min(up, left);
    //}
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // int ans = solve(m - 1, n - 1, m, n, grid);
        // return ans;
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0) {
                    dp[row][col] = grid[row][col];
                    continue;
                }
                int up = 1e9;
                int left = 1e9;
                if (row > 0)
                    up = grid[row][col] + dp[row - 1][col];

                if (col > 0)
                    left = grid[row][col] + dp[row][col - 1];

                dp[row][col] = min(left, up);
            }
        }
        return dp[m - 1][n - 1];
    }
};
class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid) {
        if (row == 0 && col == 0) {
            return grid[0][0];
        }

        int up = INT_MAX;
        if (row - 1 >= 0)
            up = grid[row][col] + solve(row - 1, col, grid);
        int left = INT_MAX;
        if (col - 1 >= 0)
            left = grid[row][col] + solve(row, col - 1, grid);

        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(2, vector<int>(n, 0));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0) {
                    dp[0][0] = grid[0][0];
                } else {
                    int up = INT_MAX;
                    if (row - 1 >= 0)
                        up = grid[row][col] + dp[(row - 1) % 2][col];
                    int left = INT_MAX;
                    if (col - 1 >= 0)
                        left = grid[row][col] + dp[row % 2][col - 1];

                    dp[row % 2][col] = min(up, left);
                }
            }
        }

        return dp[(m - 1) % 2][n - 1];
        //return solve(m - 1, n - 1, grid);
    }
};
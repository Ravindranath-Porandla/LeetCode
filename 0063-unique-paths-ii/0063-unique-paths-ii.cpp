class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0) {
                    dp[row][col] == 1;
                } else {
                    int up = 0;
                    int left = 0;
                    if (row >= 1 && obstacleGrid[row][col] != 1)
                        up = dp[row - 1][col];
                    if (col >= 1 && obstacleGrid[row][col] != 1)
                        left = dp[row][col - 1];

                    dp[row][col] = up + left;
                }
            }
        }
        return -1 * dp[m - 1][n - 1];
    }
};
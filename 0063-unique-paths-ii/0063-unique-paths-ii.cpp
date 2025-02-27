class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid){
        if(row == 0 && col == 0){
            return 1;
        }

        if(row < 0 || col < 0 || grid[row][col] == 1){
            return 0;
        }

        int top = solve(row - 1, col, grid);
        int left = solve(row, col - 1, grid);

        return top + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m - 1][n - 1] == 1){
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, 0));

        int col = 0;
        while(col < n && grid[0][col] == 0){
            dp[0][col] = 1;
            col++;
        }

        int row = 0;
        while(row < m && grid[row][0] == 0){
            dp[row][0] = 1;
            row++;
        }

        for(int row = 1; row < m; row++){
            for(int col = 1; col < n; col++){
                int up = 0;
                if(grid[row - 1][col] == 0){
                    up = dp[row - 1][col];
                }
                int left = 0;
                if(grid[row][col - 1] == 0){
                    left = dp[row][col - 1];
                }

                dp[row][col] = left + up;
            }
        }

        //return solve(m - 1, n - 1, grid);
        return dp[m - 1][n - 1];
    }
};
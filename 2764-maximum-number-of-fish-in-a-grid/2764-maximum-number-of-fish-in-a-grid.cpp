class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& vis, vector<int>& del_row,
            vector<int>& del_col) {
        int x = 0;
        x += grid[row][col];
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + del_row[i];
            int ncol = col + del_col[i];
            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                ncol < grid[0].size() && !vis[nrow][ncol] && grid[nrow][ncol] > 0) {
                x += dfs(nrow, ncol, grid, vis, del_row, del_col);
            }
        }

        return x;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> del_row = {1, -1, 0, 0};
        vector<int> del_col = {0, 0, 1, -1};

        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    res = max(res, dfs(i, j, grid, vis, del_row, del_col));
                }
            }
        }

        return res;
    }
};
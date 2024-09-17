class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int n, int m, int drow[], int dcol[]) {
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
                grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, grid, vis, n, m, drow, dcol);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int drow[] = {0, 0, -1, 1};
        int dcol[] = {1, -1, 0, 0};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, grid, vis, n, m, drow, dcol);
            }
            if (grid[i][n - 1] == 1 && !vis[i][n - 1]) {
                dfs(i, n - 1, grid, vis, n, m, drow, dcol);
            }
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && !vis[0][j]) {
                dfs(0, j, grid, vis, n, m, drow, dcol);
            }
            if (grid[m - 1][j] == 1 && !vis[m - 1][j]) {
                dfs(m - 1, j, grid, vis, n, m, drow, dcol);
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
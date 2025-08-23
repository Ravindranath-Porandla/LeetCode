class Solution {
public:
    int find(int row, int row2, int col, int col2, vector<vector<int>>& grid) {
        if (row > row2 || col > col2) {
            return 20000;
        }
        int n = grid.size(), m = grid[0].size();
        int mnx = n, mxx = 0, mny = m, mxy = 0;
        for (int i = row; i <= row2; i++) {
            for (int j = col; j <= col2; j++) {
                if (grid[i][j] == 1) {
                    mnx = min(mnx, i);
                    mxx = max(mxx, i);
                    mny = min(mny, j);
                    mxy = max(mxy, j);
                }
            }
        }
        return max(0, (mxx - mnx + 1) * (mxy - mny + 1));
    }
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a1 = find(0, i, 0, j, grid) +
                         find(0, i, j + 1, m - 1, grid) +
                         find(i + 1, n - 1, 0, m - 1, grid);
                int a2 = find(0, i, 0, m - 1, grid) +
                         find(i + 1, n - 1, 0, j, grid) +
                         find(i + 1, n - 1, j + 1, m - 1, grid);
                ans = min(ans, a1);
                ans = min(ans, a2);
            }
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                int a1 = find(0, i, 0, j, grid) +
                         find(i + 1, n - 1, 0, j, grid) +
                         find(0, n - 1, j + 1, m - 1, grid);
                int a2 = find(0, n - 1, 0, j, grid) +
                         find(0, i, j + 1, m - 1, grid) +
                         find(i + 1, n - 1, j + 1, m - 1, grid);
                ans = min({ans, a1, a2});
            }
        }
        for (int i = 0; i < n; i++) {
            for (int i2 = i; i2 < n; i2++) {
                int a1 = find(0, i, 0, m - 1, grid) +
                         find(i + 1, i2, 0, m - 1, grid) +
                         find(i2 + 1, n - 1, 0, m - 1, grid);
                ans = min(ans, a1);
            }
        }
        for (int j = 0; j < m; j++) {
            for (int j2 = j; j2 < m; j2++) {
                int a1 = find(0, n - 1, 0, j, grid) +
                         find(0, n - 1, j + 1, j2, grid) +
                         find(0, n - 1, j2 + 1, m - 1, grid);
                ans = min(ans, a1);
            }
        }
        return ans;
    }
};
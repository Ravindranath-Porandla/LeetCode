class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>& grid, int id,
            vector<int>& del_rows, vector<int>& del_cols) {
        int x = 1;
        grid[row][col] = id;

        // vector<int> del_rows = {1, -1, 0, 0};
        // vector<int> del_cols = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + del_rows[i];
            int ncol = col + del_cols[i];

            if (nrow >= 0 && ncol >= 0 && nrow < grid.size() &&
                ncol < grid.size() && grid[nrow][ncol] == 1) {
                x += dfs(nrow, ncol, grid, id, del_rows, del_cols);
            }
        }
        return x;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> del_rows = {0, 0, -1, 1};
        vector<int> del_cols = {1, -1, 0, 0};

        int res = 0;
        unordered_map<int, int> mp;
        int id = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, grid, id, del_rows, del_cols);
                    res = max(res, size);
                    mp[id] = size;
                    id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;

                    for (int x = 0; x < 4; x++) {
                        int nrow = i + del_rows[x];
                        int ncol = j + del_cols[x];

                        if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n) {
                            st.insert(grid[nrow][ncol]);
                        }
                    }
                    int size = 1;

                    for (auto& it : st) {
                        size += mp[it];
                    }

                    res = max(res, size);
                }
            }
        }
        return res;
    }
};
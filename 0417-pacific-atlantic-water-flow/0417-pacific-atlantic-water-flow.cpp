class Solution {
public:
    bool both(vector<vector<int>>& vis) {
        int n = vis.size();
        int m = vis[0].size();
        bool pacific = false;
        bool atlantic = false;

        for (int i = 0; i < m; i++) {
            if (vis[0][i])
                pacific = true;
            if (vis[n - 1][i])
                atlantic = true;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i][0])
                pacific = true;
            if (vis[i][m - 1])
                atlantic = true;
        }

        return (pacific && atlantic);
    }

    void DFS(int row, int col, vector<vector<int>>& heights,
             vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int n = heights.size();
        int m = heights[0].size();
        int del_rows[] = {0, -1, 0, 1};
        int del_cols[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++) {
            int nrow = del_rows[i] + row;
            int ncol = del_cols[i] + col;

            if ((nrow >= 0 && ncol >= 0) && (nrow < n && ncol < m) &&
                (!vis[nrow][ncol])) {
                if ((heights[nrow][ncol] <= heights[row][col]))
                    DFS(nrow, ncol, heights, vis);
            }
        }
        return;
    }

    void fill_zeros(vector<vector<int>>& vis){
        for(int i = 0; i < vis.size(); i++){
            for(int j = 0; j < vis[0].size(); j++){
                vis[i][j] = 0;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                DFS(i, j, heights, vis);
                if (both(vis)) {
                    res.push_back({i, j});
                }
                fill_zeros(vis);
            }
        }

        return res;
    }
};
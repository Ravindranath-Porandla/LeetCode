class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            mat[i][i] = 0; 
        }

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][via] != INT_MAX && mat[via][j] != INT_MAX) {
                        mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                    }
                }
            }
        }

        int cnt = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int curr_cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && mat[i][j] <= distanceThreshold) {
                    curr_cnt++;
                }
            }
            if (curr_cnt < cnt) {
                cnt = curr_cnt;
                ans = i;
            } else if (curr_cnt == cnt) {
                ans = max(ans, i);
            }
        }

        return ans;
    }
};

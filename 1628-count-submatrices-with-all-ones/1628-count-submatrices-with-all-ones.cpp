class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int res = 0;
        vector<int> height(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    height[j] = 0;
                else
                    height[j] += 1;
            }

            for (int j = 0; j < n; j++) {
                int minHt = height[j];
                for (int k = j; k >= 0 && minHt > 0; k--) {
                    minHt = min(minHt, height[k]);
                    res += minHt;
                }
            }
        }
        return res;
    }
};
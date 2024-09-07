class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& tri, vector<vector<int>>& dp) {
        if (row == 0 && col == 0)
            return tri[0][0];

        if (row < 0 || col < 0 || col > row)
            return 1e9;

        if(dp[row][col] != -1)
            return dp[row][col];

        int up = tri[row][col] + solve(row - 1, col, tri, dp);
        int up_left = tri[row][col] + solve(row - 1, col - 1, tri, dp);

        return dp[row][col] = min(up, up_left);
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int m = tri.size();
        int n = tri[m - 1].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, solve(m - 1, i, tri, dp));
        }
        return ans;
    }
};
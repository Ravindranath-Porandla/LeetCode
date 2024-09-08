class Solution {
public:
    // int solve(int row, int col, int m, int n, vector<vector<int>>& matrix,
    //           vector<vector<int>>& dp) {
    //     if (row < 0 || col < 0 || col >= n || row >= m)
    //         return 1e9;
    //     if (row == 0) {
    //         return matrix[row][col];
    //     }
    //     if (dp[row][col] != -1)
    //         return dp[row][col];
    //     int up = matrix[row][col] + solve(row - 1, col, m, n, matrix, dp);
    //     int left_dia =
    //         matrix[row][col] + solve(row - 1, col - 1, m, n, matrix, dp);
    //     int right_dia =
    //         matrix[row][col] + solve(row - 1, col + 1, m, n, matrix, dp);

    //     return dp[row][col] = min(up, min(left_dia, right_dia));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(2, vector<int>(n, -1));
        // int ans = INT_MAX;
        // for (int i = 0; i < n; i++) {
        //     ans = min(ans, solve(m - 1, i, m, n, matrix, dp));
        // }

        for (int col = 0; col < n; col++)
            dp[0][col] = matrix[0][col];

        for (int row = 1; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int up = matrix[row][col] + dp[(row - 1) % 2][col];
                int left_dia = 1e9;
                if (col - 1 >= 0)
                    left_dia = matrix[row][col] + dp[(row - 1) % 2][col - 1];
                int right_dia = 1e9;
                if (col + 1 < n)
                    right_dia = matrix[row][col] + dp[(row - 1) % 2][col + 1];

                dp[row % 2][col] = min(up, min(left_dia, right_dia));
            }
        }

        int ans = dp[(m - 1) % 2][0];
        for (int col = 1; col < n; col++) {
            ans = min(ans, dp[(m - 1) % 2][col]);
        }
        return ans;
    }
};
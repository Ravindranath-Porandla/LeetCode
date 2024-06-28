class Solution {
public:
    // int solve(int i, int j, int n, vector<vector<int>>& matrix,
    //           vector<vector<int>>& dp) {
    //     if (i < 0 || j < 0 || j >= n)
    //         return 1e9;
    //     if (i == 0)
    //         return matrix[0][j];
    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int up = matrix[i][j] + solve(i - 1, j, n, matrix, dp);
    //     int dia_left = matrix[i][j] + solve(i - 1, j - 1, n, matrix, dp);
    //     int dia_right = matrix[i][j] + solve(i - 1, j + 1, n, matrix, dp);

    //     return dp[i][j] = min(up, min(dia_left, dia_right));
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        //  int mini = INT_MAX;
        //  for (int j = 0; j < n; j++) {
        //      int ans = solve(n - 1, j, n, matrix, dp);
        //      mini = min(mini, ans);
        //  }
        //  return mini;

        // vector<vector<int>> dp(n, vector<int>(n, 1e9));

        // Initialize the first row of dp with the first row of the matrix

        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        // Fill the dp table
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = matrix[i][j] + dp[i - 1][j];
                int dia_left = (j > 0) ? matrix[i][j] + dp[i - 1][j - 1] : 1e9;
                int dia_right =
                    (j < n - 1) ? matrix[i][j] + dp[i - 1][j + 1] : 1e9;

                dp[i][j] = min(up, min(dia_left, dia_right));
            }
        }

        // Find the minimum value in the last row of dp
        int mini = INT_MAX;
        for (int j = 0; j < n; ++j) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }
};
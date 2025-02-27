class Solution {
public:
    // int solve(int row, int col, vector<vector<int>>& mat) {
    //     if (row == 0) {
    //         return mat[0][col];
    //     }

    //     int up = INT_MAX;
    //     int leftDia = INT_MAX;
    //     int rightDia = INT_MAX;

    //     up = mat[row][col] + solve(row - 1, col, mat);

    //     if (col - 1 >= 0)
    //         leftDia = mat[row][col] + solve(row - 1, col - 1, mat);

    //     if (col + 1 < mat.size())
    //         rightDia = mat[row][col] + solve(row - 1, col + 1, mat);

    //     return min(leftDia, min(rightDia, up));
    // }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();

        // int ans = INT_MAX;
        // for (int i = 0; i < n; i++) {
        //     ans = min(ans, solve(n - 1, i, mat));
        // }

        vector<vector<int>> dp(2, vector<int>(n, 0));

        for (int col = 0; col < n; col++) {
            dp[0][col] = mat[0][col];
        }

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int up = INT_MAX;
                int leftDia = INT_MAX;
                int rightDia = INT_MAX;

                up = mat[row][col] + dp[(row - 1) % 2][col];

                if (col - 1 >= 0)
                    leftDia = mat[row][col] + dp[(row - 1) % 2][col - 1];

                if (col + 1 < mat.size())
                    rightDia = mat[row][col] + dp[(row - 1) % 2][col + 1];

                dp[row % 2][col] = min(leftDia, min(rightDia, up));
            }
        }

        int ans = INT_MAX;

        for(int col = 0; col < n; col++){
            ans = min(ans, dp[(n - 1) % 2][col]);
        }

        return ans;
    }
};
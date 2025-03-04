class Solution {
public:
    // int solve(int idx1, int idx2, string text1, string text2) {
    //     if (idx1 == 0 || idx2 == 0) {
    //         return 0;
    //     }

    //     int take = 0;
    //     if (text1[idx1 - 1] == text2[idx2 - 1]) {
    //         take = 1 + solve(idx1 - 1, idx2 - 1, text1, text2);
    //     }

    //     int not_take = max(solve(idx1 - 1, idx2, text1, text2),
    //                        solve(idx1, idx2 - 1, text1, text2));

    //     return max(take, not_take);
    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        //return solve(n, m, text1, text2);

        vector<vector<int>> dp(2, vector<int>(m + 1, 0));

        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                int take = 0;
                if (text1[idx1 - 1] == text2[idx2 - 1]) {
                    take = 1 + dp[(idx1 - 1) % 2][idx2 - 1];
                }

                int not_take = max(dp[(idx1 - 1) % 2][idx2],
                                   dp[idx1 % 2][idx2 - 1]);

                dp[idx1 % 2][idx2] = max(take, not_take);
            }
        }

        return dp[n % 2][m];
    }
};
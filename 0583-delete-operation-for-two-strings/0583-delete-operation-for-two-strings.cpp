class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                if (word1[idx1 - 1] == word2[idx2 - 1]) {
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                } else {
                    dp[idx1][idx2] =
                        max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
                }
            }
        }

        return n + m - 2*dp[n][m];
    }
};
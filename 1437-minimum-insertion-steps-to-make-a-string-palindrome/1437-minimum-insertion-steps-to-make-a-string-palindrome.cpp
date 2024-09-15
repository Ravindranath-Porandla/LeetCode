class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= n; idx2++) {
                if (s[idx1 - 1] == t[idx2 - 1]) {
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                } else {
                    dp[idx1][idx2] =
                        max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
                }
            }
        }

        return s.size() - dp[n][n];
    }
};
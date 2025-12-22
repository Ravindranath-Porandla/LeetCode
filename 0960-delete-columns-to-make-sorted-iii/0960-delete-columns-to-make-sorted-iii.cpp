class Solution {
public:
    static int minDeletionSize(vector<string>& strs) {
        const int n = strs.size(), m = strs[0].size();

        int dp[2][101] = {0};

        for (int last = 1; last <= m; last++) {
            bool ok = (last == m) ||
                      all_of(strs.begin(), strs.end(),
                             [&](const string& s) { return s[0] <= s[last]; });
            dp[0][last] = ok;
        }

        for (int col = 1; col < m; col++) {
            const bool b = col & 1;
            for (int last = col + 1; last <= m; last++) {
                dp[b][last] = dp[!b][last];

                bool ok = (last == m) || all_of(strs.begin(), strs.end(),
                                                [&](const string& s) {
                                                    return s[col] <= s[last];
                                                });

                if (ok)
                    dp[b][last] = max(dp[b][last], 1 + dp[!b][col]);
            }
        }
        return m - dp[(m - 1) & 1][m];
    }
};

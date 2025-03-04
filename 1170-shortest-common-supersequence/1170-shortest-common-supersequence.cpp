class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                int take = 0;
                if (text1[idx1 - 1] == text2[idx2 - 1]) {
                    take = 1 + dp[idx1 - 1][idx2 - 1];
                }

                int not_take = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);

                dp[idx1][idx2] = max(take, not_take);
            }
        }

        int idx1 = n;
        int idx2 = m;
        string ans = "";

        while (idx1 > 0 && idx2 > 0) {
            if (text1[idx1 - 1] == text2[idx2 - 1]) {
                ans.push_back(text1[idx1 - 1]);
                idx1--;
                idx2--;
            } else if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1]) {
                ans.push_back(text1[idx1 - 1]);
                idx1--;
            } else {
                ans.push_back(text2[idx2 - 1]);
                idx2--;
            }
        }
        while (idx1 > 0) {
            ans.push_back(text1[idx1 - 1]);
            idx1--;
        }
        while (idx2 > 0) {
            ans.push_back(text2[idx2 - 1]);
            idx2--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
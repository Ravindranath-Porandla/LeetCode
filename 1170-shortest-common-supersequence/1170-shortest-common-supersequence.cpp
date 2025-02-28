class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int idx1 = 1; idx1 <= n; idx1++) {
            for (int idx2 = 1; idx2 <= m; idx2++) {
                if (str1[idx1 - 1] == str2[idx2 - 1]) {
                    dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                } else {
                    dp[idx1][idx2] =
                        max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
                }
            }
        }

        string ans = "";

        int idx1 = n;
        int idx2 = m;
        while (idx1 > 0 && idx2 > 0) {
            if (str1[idx1 - 1] == str2[idx2 - 1]) {
                ans.push_back(str1[idx1 - 1]);
                idx1--;
                idx2--;
            } else if (dp[idx1][idx2 - 1] > dp[idx1 - 1][idx2]) {
                ans.push_back(str2[idx2 - 1]);
                idx2--;
            } else {
                ans.push_back(str1[idx1 - 1]);
                idx1--;
            }
        }

        while (idx1 > 0) {
            ans.push_back(str1[idx1 - 1]);
            idx1--;
        }
        while (idx2 > 0) {
            ans.push_back(str2[idx2 - 1]);
            idx2--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
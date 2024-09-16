class Solution {
public:
    bool solve(int i, int j, const string& s, const string& p,
               vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return check(p, j);
        if (i >= 0 && j < 0)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (p[j] == '*') {
            return dp[i][j] =
                       solve(i - 1, j, s, p, dp) || solve(i, j - 1, s, p, dp);
        }
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool check(const string& p, int j) {
        for (int i = 0; i <= j; i++)
            if (p[i] != '*')
                return false;
        return true;
    }

    bool isMatch(const string& s, const string& p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n - 1, m - 1, s, p, dp);
    }
};

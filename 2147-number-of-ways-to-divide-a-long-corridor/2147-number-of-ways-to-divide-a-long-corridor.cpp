class Solution {
public:
    const int M = 1e9 + 7;
    int helper(int i, int seats, string& corridor, vector<vector<int>>& dp) {
        if (i < 0) {
            if (seats == 2)
                return 1;
            return 0;
        }
        if (dp[i][seats] != -1)
            return dp[i][seats];
        int ways = 0;
        if (seats == 2) {
            if (corridor[i] == 'S') {
                ways = helper(i - 1, 1, corridor, dp);
            } else {
                ways = (helper(i - 1, seats, corridor, dp) +
                        helper(i - 1, 0, corridor, dp)) %
                       M;
            }
        } else {
            if (corridor[i] == 'S') {
                ways = helper(i - 1, seats + 1, corridor, dp);
            } else {
                ways = helper(i - 1, seats, corridor, dp);
            }
        }
        return dp[i][seats] = ways;
    }
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return helper(n - 1, 0, corridor, dp);
    }
};
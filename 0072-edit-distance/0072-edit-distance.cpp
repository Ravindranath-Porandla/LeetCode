class Solution {
public:
    int solve(int i, int j, string word1, string word2, vector<vector<int>>& dp) {
        if(i == 0)   return j;
        if(j == 0)   return i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        } else {
            return dp[i][j] = 1 + min(solve(i, j - 1, word1, word2, dp),
                           min(solve(i - 1, j, word1, word2, dp),
                           solve(i - 1, j - 1, word1, word2, dp)));
        }
    }
    int minDistance(string word1, string word2) {
        if(word1 == word2)  return 0;
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = solve(n, m, word1, word2, dp);
        return ans;
    }
};
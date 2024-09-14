class Solution {
public:
    // int solve(int idx1, int idx2, string text1, string text2, vector<vector<int>>& dp){
    //     if(idx1 == 0 || idx2 == 0){
    //         return 0;
    //     }

    //     if(dp[idx1][idx2] != -1)
    //         return dp[idx1][idx2];
    //     if(text1[idx1 - 1] == text2[idx2 - 1]){
    //         return dp[idx1][idx2] = 1 + solve(idx1 -1, idx2 - 1, text1, text2, dp);
    //     }
    //                 return dp[idx1][idx2] = max(solve(idx1 - 1, idx2, text1, text2, dp), 
    //                 solve(idx1, idx2 - 1, text1, text2, dp));

    // }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // int ans = solve(n, m, text1, text2, dp);
        // return ans;

        for(int idx1 = 0; idx1 <= n; idx1++)
            dp[idx1][0] = 0;
        for(int idx2 = 0; idx2 <= m; idx2++)
            dp[0][idx2] = 0;
        
        for(int idx1 = 1; idx1 <=n; idx1++){
            for(int idx2 = 1; idx2 <= m; idx2++){
                if(text1[idx1 - 1] == text2[idx2 - 1]){
                     dp[idx1][idx2] = 1 + dp[idx1 -1][idx2 - 1];
                } else {
                    dp[idx1][idx2] = max(dp[idx1 - 1][idx2], 
                    dp[idx1][idx2 - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
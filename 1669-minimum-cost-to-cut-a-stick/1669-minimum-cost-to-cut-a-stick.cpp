class Solution {
public:
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        for(int k = i; k <= j; k++){
            mini = min(mini, (cuts[j + 1] - cuts[i - 1]) + solve(i, k - 1, cuts, dp) + solve(k + 1, j, cuts, dp));
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, -1));
        return solve(1, c - 2, cuts, dp);
    }
};
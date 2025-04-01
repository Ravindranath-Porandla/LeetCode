class Solution {
public:
    long long solve(int idx, vector<vector<int>>& ques, int n, vector<long long>& dp) {
        if (idx >= n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        // pick
        long long pick = 0;
        if (idx < n)
            pick = ques[idx][0] + solve(idx + ques[idx][1] + 1, ques, n, dp);

        // not_pick
        long long not_pick = 0;
        if(idx < n)
            not_pick = solve(idx + 1, ques, n, dp);

        return dp[idx] = max(pick, not_pick);
    }
    long long mostPoints(vector<vector<int>>& ques) {
        int n = ques.size();
        vector<long long> dp(n, -1);
        return solve(0, ques, n, dp);
    }
};
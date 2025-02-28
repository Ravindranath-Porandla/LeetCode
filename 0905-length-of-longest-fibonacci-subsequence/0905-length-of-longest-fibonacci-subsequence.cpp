class Solution {
public:
    int solve(int j, int k, vector<int>& arr, unordered_map<int, int>& mp, vector<vector<int>> &dp){
        if(dp[j][k] != -1)
            return dp[j][k];

        int x = arr[k] - arr[j];

        if(mp.count(x) && mp[x] < j){
            return dp[j][k] = 1 + solve(mp[x], j, arr, mp, dp);
        }

        return dp[j][k] = 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = 0;
        for(int j = 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int len = solve(j, k, arr, mp, dp);
                if(len >= 3){
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
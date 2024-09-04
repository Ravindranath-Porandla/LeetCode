class Solution {
public:
    int solve(int idx, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }

        if(dp[idx][amount] != -1)
            return dp[idx][amount];

        int pick = 1e9;
        if (amount >= coins[idx]) {
            pick = 1 + solve(idx, coins, amount - coins[idx], dp);
        }
        int not_pick = solve(idx - 1, coins, amount, dp);
        return dp[idx][amount] = min(pick, not_pick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(coins.size() - 1, coins, amount, dp);

        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};
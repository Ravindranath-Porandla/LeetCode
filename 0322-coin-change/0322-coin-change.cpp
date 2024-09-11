class Solution {
public:
    // int solve(int idx, vector<int>& coins, int amount,
    //           vector<vector<int>>& dp) {
    //     if (idx == 0) {
    //         if ((amount % coins[0]) == 0) {
    //             return amount / coins[0];
    //         } else {
    //             return 1e9;
    //         }
    //     }

    //     if (dp[idx][amount] != -1)
    //         return dp[idx][amount];

    //     int not_pick = solve(idx - 1, coins, amount, dp);
    //     int pick = INT_MAX;
    //     if (coins[idx] <= amount)
    //         pick = 1 + solve(idx, coins, amount - coins[idx], dp);

    //     return dp[idx][amount] = min(not_pick, pick);
    // }
    int coinChange(vector<int>& coins, int am) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(am + 1, -1));
        // int ans = solve(n - 1, coins, amount, dp);
        // return (ans == 1e9) ? -1 : ans;

        for (int amount = 0; amount <= am; amount++) {
            if ((amount % coins[0]) == 0)
                dp[0][amount] = amount / coins[0];
            else
                dp[0][amount] = 1e9;
        }

        for (int idx = 1; idx < n; idx++) {
            for (int amount = 0; amount <= am; amount++) {
                int not_pick = dp[idx - 1][amount];
                int pick = INT_MAX;
                if (coins[idx] <= amount)
                    pick = 1 + dp[idx][amount - coins[idx]];

                dp[idx][amount] = min(not_pick, pick);
            }
        }
        return (dp[n - 1][am] == 1e9) ? -1 : dp[n - 1][am];
    }
};
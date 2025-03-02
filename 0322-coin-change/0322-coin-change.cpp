class Solution {
public:
    // int solve(int idx, vector<int>& coins, int amount) {
    //     if (idx == 0) {
    //         if (amount % coins[0] == 0) {
    //             return amount / coins[0];
    //         } else {
    //             return 1e9;
    //         }
    //     }

    //     // pick
    //     int pick = 1e9;
    //     if (amount >= coins[idx]) {
    //         pick = 1 + solve(idx, coins, amount - coins[idx]);
    //     }

    //     // not_pick
    //     int not_pick = solve(idx - 1, coins, amount);

    //     return min(pick, not_pick);
    // }
    int coinChange(vector<int>& coins, int a) {
        int n = coins.size();
        //return solve(n - 1, coins, amount);

        vector<vector<int>> dp(2, vector<int>(a + 1, 0));

        for (int amount = 0; amount <= a; amount++) {
            if (amount % coins[0] == 0) {
                dp[0][amount] = amount / coins[0];
            } else {
                dp[0][amount] = 1e9;
            }
        }

        for (int idx = 1; idx < n; idx++) {
            for (int amount = 0; amount <= a; amount++) {
                int pick = 1e9;
                if (amount >= coins[idx]) {
                    pick = 1 + dp[idx % 2][amount - coins[idx]];
                }

                // not_pick
                int not_pick = dp[(idx - 1) % 2][amount];

                dp[idx % 2][amount] = min(pick, not_pick);
            }
        }

        return dp[(n - 1) % 2][a] >= 1e9 ? -1 : dp[(n - 1) % 2][a];
    }
};
class Solution {
public:
    // int solve(int idx, vector<int>& coins, int amount,
    //           vector<vector<int>>& dp) {
    //     if (idx == 0) {
    //         if (amount % coins[0] == 0)
    //             return 1;
    //         else
    //             return 0;
    //     }

    //     if (dp[idx][amount] != 0)
    //         return dp[idx][amount];

    //     int not_pick = solve(idx - 1, coins, amount, dp);
    //     int pick = 0;
    //     if (coins[idx] <= amount)
    //         pick = solve(idx, coins, amount - coins[idx], dp);

    //     return dp[idx][amount] = pick + not_pick;
    // }
    int change(int am, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(am + 1, -1));
        // int ans = solve(n - 1, coins, amount, dp);
        // return ans;
        for (int amount = 0; amount <= am; amount++) {
            if (amount % coins[0] == 0) {
                dp[0][amount] = 1;
            } else {
                dp[0][amount] = 0;
            }
        }

        for (int idx = 1; idx < n; idx++) {
            for (int amount = 0; amount <= am; amount++) {
                int not_pick = dp[idx - 1][amount];
                int pick = 0;
                if (coins[idx] <= amount)
                    pick = dp[idx][amount - coins[idx]];

                dp[idx][amount] = pick + not_pick;
            }
        }
        return dp[n - 1][am];
    }
};
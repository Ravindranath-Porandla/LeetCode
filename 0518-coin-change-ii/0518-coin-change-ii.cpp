class Solution {
private:
    // int solve(int amount, vector<int>& coins, int idx) {
    //     if (idx == 0) {
    //         if (amount % coins[0] == 0) {
    //             return 1;
    //         } else {
    //             return 0;
    //         }
    //     }

    //     int pick = 0;

    //     if (amount >= coins[idx])
    //         pick = solve(amount - coins[idx], coins, idx);
    //     int not_pick = solve(amount, coins, idx - 1);

    //     return pick + not_pick;
    // }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount + 1, vector<int>(n, 0));
        for(int amt = 0; amt <= amount; amt++)
            if (amt % coins[0] == 0)
                dp[amt][0] = 1;

            for (int amt = 0; amt <= amount; amt++) {
                for (int idx = 1; idx < n; idx++) {
                    int pick = 0;

                    if (amt >= coins[idx]) {
                        pick = dp[amt - coins[idx]][idx];
                    }
                    int not_pick = dp[amt][idx - 1];

                    dp[amt][idx] = pick + not_pick;
                }
            }

        return dp[amount][n - 1];
    }
};
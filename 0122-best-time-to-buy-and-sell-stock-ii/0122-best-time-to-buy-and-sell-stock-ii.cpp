class Solution {
public:
    int solve(int idx, int canBuy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx == prices.size()){
            return 0;
        }

        if(dp[idx][canBuy] != -1)
            return dp[idx][canBuy];

        int profit = 0;
        if(canBuy){
            profit = max(solve(idx + 1, 0, prices, dp) - prices[idx], 
                        solve(idx + 1, 1, prices, dp));
        } else {
            profit = max(solve(idx + 1, 1, prices, dp) + prices[idx],
                        solve(idx + 1, 0, prices, dp));
        }

        return dp[idx][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
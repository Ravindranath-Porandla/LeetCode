class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int maxi = 0;
        int n = prices.size();

        for(int i = n - 1; i >= 0; i--){
            maxi = max(maxi, prices[i]);
            ans = max(ans, maxi - prices[i]);
        }

        return ans;
    }
};
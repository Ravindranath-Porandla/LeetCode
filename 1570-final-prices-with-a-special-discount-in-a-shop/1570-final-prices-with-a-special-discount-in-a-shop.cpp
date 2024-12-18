class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;

        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && prices[i] < prices[st.top()]) {
                st.pop();
            }
            ans[i] = (st.empty() ? prices[i] : prices[i] - prices[st.top()]);
            st.push(i);
        }
        return ans;
    }
};
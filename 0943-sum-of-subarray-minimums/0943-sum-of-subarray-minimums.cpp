class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;

        vector<int> nsl(n, 0);
        vector<int> nsr(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()])
                st.pop();

            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] < arr[st.top()])
                st.pop();

            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int mod = 1e9 + 7;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - nsl[i];
            long long right = nsr[i] - i;
            ans = (ans + arr[i] * left % mod * right % mod) % mod;
        }

        return ans;
    }
};
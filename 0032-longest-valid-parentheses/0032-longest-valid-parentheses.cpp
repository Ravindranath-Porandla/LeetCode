class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    int len = i - st.top();
                    maxi = max(maxi, len);
                }
            }
        }

        return maxi;
    }
};
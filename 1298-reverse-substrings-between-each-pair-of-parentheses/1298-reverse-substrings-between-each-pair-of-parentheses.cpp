class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                string temp = "";
                while (st.top() != '(') {
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop(); // Pop the '('

                // Push the reversed substring back onto the stack
                for (int j = 0; j < temp.size(); j++)
                    st.push(temp[j]);
            } else {
                st.push(s[i]);
            }
        }

        // Construct the result string from the stack
        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        // Reverse the result string to get the correct order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

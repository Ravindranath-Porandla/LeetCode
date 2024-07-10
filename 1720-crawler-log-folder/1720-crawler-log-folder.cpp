class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for (string log : logs) {
            if (log == "./") {
                continue;
            } else if (log == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(log);
            }
        }

        return st.size();
    }
};
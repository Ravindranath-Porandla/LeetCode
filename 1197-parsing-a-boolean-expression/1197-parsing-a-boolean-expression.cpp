class Solution {
public:
    char solve(vector<int>& vec, char op) {
        if (op == '!') {
            return vec[0] == 't' ? 'f' : 't';
        }
        if (op == '&') {
            for (char ch : vec) {
                if (ch == 'f') {
                    return 'f';
                }
            }
            return 't';
        }
        if (op == '|') {
            for (char ch : vec) {
                if (ch == 't') {
                    return 't';
                }
            }
            return 'f';
        }
        return 'f';
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();

        stack<char> st;

        for (char ch : expression) {
            if (ch == ',') {
                continue;
            } else if (ch == ')') {
                vector<int> vec;
                while (st.top() != '(') {
                    vec.push_back(st.top());
                    st.pop();
                }

                st.pop();
                char op = st.top();
                st.pop();
                st.push(solve(vec, op));
            } else {
                st.push(ch);
            }
        }

        return st.top() == 't' ? true : false;
    }
};
class Solution {
public:
    void solve(int n, string str, set<string>& st) {
        if (str.size() == n) {
            st.insert(str);
            return;
        }

        string letters = "abc";

        for (char ch : letters) {
            if (str.empty() || str.back() != ch)
                solve(n, str + ch, st);
        }
    }

    string getHappyString(int n, int k) {
        set<string> st;
        string str = "";
        solve(n, str, st);

        if (st.size() < k)
            return "";

        int i = 1;
        for (const auto& it : st) {
            if (i == k)
                return it;
            i++;
        }

        return "";
    }
};

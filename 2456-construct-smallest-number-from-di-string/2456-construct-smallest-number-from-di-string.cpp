class Solution {
public:
    bool check(string str, string pattern) {
        for (int i = 1; i < str.size(); i++) {
            if (str[i] > str[i - 1] && pattern[i - 1] != 'I')
                return false;
            if (str[i] < str[i - 1] && pattern[i - 1] != 'D')
                return false;
        }
        return true;
    }
    void solve(string& str, string pattern, set<string>& st, vector<int>& vis) {
        if (str.size() == pattern.size() + 1) {
            if (check(str, pattern)) {
                st.insert(str);
            }
            return;
        }

        for (int i = 1; i <= pattern.size() + 1; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                str.push_back('0' + i);
                solve(str, pattern, st, vis);
                str.pop_back();
                vis[i] = 0;
            }
        }
    }
    string smallestNumber(string pattern) {
        string str = "";
        set<string> st;
        vector<int> vis(pattern.size() + 2, 0);
        solve(str, pattern, st, vis);
        string ans = *st.begin();
        return ans;
    }
};
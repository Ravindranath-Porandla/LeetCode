class Solution {
public:
    int solve(int idx, string s, unordered_set<string>& st) {
        if (idx == s.size()) {
            return 0;
        }
        int ans = INT_MIN;
        for (int i = idx; i < s.size(); i++) {
            string sub = s.substr(idx, i - idx + 1);
            if (st.find(sub) == st.end()){
                st.insert(sub);
                ans = max(ans, 1 + solve(i + 1, s, st));
                st.erase(sub);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int ans = solve(0, s, st);
        return ans;
    }
};
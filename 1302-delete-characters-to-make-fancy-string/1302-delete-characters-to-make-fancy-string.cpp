class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            if (ans.length() >= 2 && ans[ans.length() - 2] == s[i] &&
                ans[ans.length() - 1] == s[i])
                continue;

            ans.push_back(s[i]);
        }
        return ans;
    }
};
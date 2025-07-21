class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string res = "";

        for (int i = 0; i < n; i++) {
            if (i < 2 ||
                (res[res.size() - 1] != s[i] || res[res.size() - 2] != s[i])) {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};
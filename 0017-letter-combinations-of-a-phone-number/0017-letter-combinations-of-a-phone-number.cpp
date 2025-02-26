class Solution {
public:
    void solve(int idx, string digits, string& ds, vector<string> &ans,
               unordered_map<char, string>& mp) {
        if (idx == digits.size()) {
            ans.push_back(ds);
            return;
        }

        for (auto ch : mp[digits[idx]]) {
            ds.push_back(ch);
            solve(idx + 1, digits, ds, ans, mp);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        vector<string> ans;
        string ds;

        solve(0, digits, ds, ans, mp);
        return ans;
    }
};
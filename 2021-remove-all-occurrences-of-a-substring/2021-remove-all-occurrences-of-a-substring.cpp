class Solution {
public:
    bool check(string res, string part) {
        int i = res.size() - 1;
        int j = part.size() - 1;

        while (i >= 0 && j >= 0) {
            if (res[i] != part[j]) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        int m = s.size();
        int n = part.size();

        string res = "";

        for (char ch : s) {
            res.push_back(ch);
            if (res.size() >= n && check(res, part)) {
                for (int j = 0; j < n; j++) {
                    res.pop_back();
                }
            }
        }
        return res;
    }
};
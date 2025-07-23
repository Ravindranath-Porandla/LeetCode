class Solution {
public:
    pair<int, string> solve(string& s, string temp, int points) {
        int char1 = temp[0];
        int char2 = temp[1];
        string modified;
        int res = 0;

        for (char ch : s) {
            if (modified.size() && ch == char2 && modified.back() == char1) {
                res += points;
                modified.pop_back();
            } else {
                modified.push_back(ch);
            }
        }

        return {res, modified};
    }
    int maximumGain(string s, int x, int y) {
        int res = 0;
        if (x >= y) {
            auto a = solve(s,"ab", x);
            res += a.first;
            auto b = solve(a.second, "ba", y);
            res += b.first;
        } else {
            auto a = solve(s, "ba", y);
            res += a.first;
            auto b = solve(a.second, "ab", x);
            res += b.first;
        }

        return res;
    }
};
class Solution {
public:
    string solve(string s, string matchString) {
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            s[i] = s[j];
            i++;
            if (i >= 2 && s[i - 2] == matchString[0] &&
                s[i - 1] == matchString[1])
                i -= 2;
        }

        s.erase(s.begin() + i, s.end());
        return s;
    }
    int maximumGain(string s, int x, int y) {
        string maxString = (x > y) ? "ab" : "ba";
        string minString = (x < y) ? "ab" : "ba";
        int ans = 0;
        string temp1 = solve(s, maxString);
        int len = s.size() - temp1.size();
        ans += (len / 2) * max(x, y);
        string temp2 = solve(temp1, minString);
        len = temp1.size() - temp2.size();
        ans += (len / 2) * min(x, y);
        return ans;
    }
};
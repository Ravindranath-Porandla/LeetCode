class Solution {
public:
    string clearDigits(string s) {
        string res = "";

        for (char ch : s) {
            if (ch >= '0' && ch <= '9') {
                res.pop_back();
            } else {
                res.push_back(ch);
            }
        }

        return res;
    }
};
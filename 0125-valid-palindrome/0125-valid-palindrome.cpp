class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (!isalpha(s[i]) && !isdigit(s[i]))
                continue;
            char ch = s[i];
            ch = tolower(ch);
            str.append(string(1, ch));
        }
        string str2 = str;
        reverse(str.begin(), str.end());
        if (str2 == str)
            return true;
        return false;
    }
};
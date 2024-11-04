class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i = 0;

        while (i < word.size()) {
            char ch = word[i];
            int cnt = 0;
            while (word[i] == ch) {
                cnt++;
                i++;
                if (cnt == 9) {
                    ans.push_back('0' + cnt);
                    ans.push_back(ch);
                    cnt = 0;
                }
            }
            if (cnt != 0) {
                ans.push_back('0' + cnt);
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
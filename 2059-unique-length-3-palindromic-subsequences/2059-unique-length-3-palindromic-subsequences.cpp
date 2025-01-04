class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26], last[26], result = 0;
        fill(begin(first), end(first), INT_MAX);
        fill(begin(last), end(last), -1);

        for (int i = 0; i < s.size(); ++i) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < 26; ++i) {
            if (first[i] < last[i]) {
                result += unordered_set<char>(s.begin() + first[i] + 1,
                                              s.begin() + last[i])
                              .size();
            }
        }

        return result;
    }
};
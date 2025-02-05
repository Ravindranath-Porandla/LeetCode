class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff1 = -1, diff2 = -1;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i] && diff1 == -1) {
                diff1 = i;
            } else if (s1[i] != s2[i] && diff2 == -1) {
                diff2 = i;
            }
        }
        if (diff1 != -1 && diff2 == -1) return false;
        if (diff1 != -1) swap(s2[diff1], s2[diff2]);
        return s1 == s2;
    }
};
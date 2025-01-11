class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size())
            return false;
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int cnt = 0;
        for (int f : freq) {
            if (f & 1) {
                cnt++;
            }
        }

        if (cnt <= k)
            return true;
        return false;
    }
};
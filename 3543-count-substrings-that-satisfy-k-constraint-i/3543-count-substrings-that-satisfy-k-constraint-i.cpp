class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int ones = 0;
            int zeroes = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    ones++;
                if (s[j] == '0')
                    zeroes++;
                if (ones <= k || zeroes <= k)
                    ans++;
            }
        }
        return ans;
    }
};
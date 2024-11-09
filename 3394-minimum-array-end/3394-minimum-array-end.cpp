class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        long long ans = x;
        int cnt = __builtin_popcount(x);

        for (int i = 63; i >= 0; i--) {
            if (((1L << i) & (ans))) {
                cnt--;
            } else if ((n >= (1L << (i - cnt)))) {
                ans = ans | (1L << i);
                n = n - (1L << (i - cnt));
            }
            if (n <= 0)
                return ans;
        }
        return ans;
    }
};
class Solution {
public:
    long long countHelper(long long num, long long maxDigit, string suffix) {
        string strNum = to_string(num);
        int diff = strNum.size() - suffix.size();
        if (diff < 0)
            return 0;

        vector<vector<long long>> dp(diff + 1, vector<long long>(2, 0));
        dp[diff][0] = 1;
        dp[diff][1] = strNum.substr(diff) >= suffix ? 1 : 0;

        for (int i = diff - 1; i >= 0; --i) {
            int digit = strNum[i] - '0';
            dp[i][0] = (maxDigit + 1) * dp[i + 1][0];
            if (digit <= maxDigit) {
                dp[i][1] = (long long)digit * dp[i + 1][0] + dp[i + 1][1];
            } else {
                dp[i][1] = (long long)(maxDigit + 1) * dp[i + 1][0];
            }
        }

        return dp[0][1];
    }

    long long numberOfPowerfulInt(long long start, long long end, int maxDigit,
                                  string suffix) {
        return countHelper(end, maxDigit, suffix) -
               countHelper(start - 1, maxDigit, suffix);
    }
};

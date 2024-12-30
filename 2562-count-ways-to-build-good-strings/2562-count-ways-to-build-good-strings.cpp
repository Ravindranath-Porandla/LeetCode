class Solution {
public:
    long long solve(int curLen, int low, int high, int zero, int one,
              vector<long long>& dp) {
        // Base case: If the current length exceeds high, terminate
        if (curLen > high)
            return 0;

        // If the result for this length has already been computed, return it
        if (dp[curLen] != -1)
            return dp[curLen];

        // Count this string if its length is within [low, high]
        long long count = (curLen >= low) ? 1 : 0;

        // Append zeros
        count += solve(curLen + zero, low, high, zero, one, dp);

        // Append ones
        count += solve(curLen + one, low, high, zero, one, dp);

        // Store the result in dp array and return it
        return dp[curLen] = (count % (int)(1e9 + 7));
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // Create a dp array to store results for lengths up to `high`
        vector<long long> dp(high + 1, -1);
        return (int)(solve(0, low, high, zero, one, dp) % ((int)1e9 + 7));
    }
};

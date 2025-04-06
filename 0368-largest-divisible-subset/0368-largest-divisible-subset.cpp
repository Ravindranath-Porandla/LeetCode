class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1);
        vector<int> h(n, 0);
        int maxLen = 1;
        int lastIdx = 0;
        for (int i = 1; i < n; i++) {
            h[i] = i;
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] % arr[prev] == 0 && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                    h[i] = prev;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        vector<int> ans;
        ans.push_back(arr[lastIdx]);
        while (h[lastIdx] != lastIdx) {
            lastIdx = h[lastIdx];
            ans.push_back(arr[lastIdx]);
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};
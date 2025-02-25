class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        long long sum = 0, count = 0;
        int oddCount = 0, evenCount = 1;

        int prefixSum = 0;
        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 0) {
                count = (count + oddCount) % MOD;
                evenCount++;
            } else {
                count = (count + evenCount) % MOD;
                oddCount++;
            }
        }

        return count % MOD;
    }
};

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int num : nums) {
            sum += num;
        }

        int n = nums.size();
        int target = sum % p;
        if (target == 0) {
            return 0; // Already divisible by p
        }

        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = -1; // To handle cases where we remove subarrays
                              // starting from index 0

        long long prefixSum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; ++right) {
            prefixSum = (prefixSum + nums[right]) % p;

            // Find the modulo we need to remove
            int need = (prefixSum - target + p) % p;

            // Check if the required prefix modulo exists in the map
            if (prefixSumMap.find(need) != prefixSumMap.end()) {
                minLen = min(minLen, right - prefixSumMap[need]);
            }

            // Store the current prefix modulo with its index
            prefixSumMap[prefixSum] = right;
        }

        // Return -1 if no valid subarray was found or the entire array must be
        // removed
        return (minLen == INT_MAX || minLen == n) ? -1 : minLen;
    }
};

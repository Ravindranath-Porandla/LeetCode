class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        long long res = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            res += mp[key];
            mp[key]++;
        }

        return (n * (n - 1)) / 2 - res;
    }
};
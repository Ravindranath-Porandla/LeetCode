class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int i = 0;
        int j = max(i, mp[nums[i]]);
        int ans = 1;

        while (i < n) {
            if (j < i) {
                ans = (ans % mod * 2) % mod;
            }
            j = max(j, mp[nums[i]]);
            i++;
        }
        return ans % mod;
    }
};
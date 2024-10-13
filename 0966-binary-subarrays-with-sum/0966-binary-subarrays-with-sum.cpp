class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        int preSum = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            preSum += nums[i];
            int remove = preSum - k;
            ans += mp[remove];
            mp[preSum]++;
        }
        return ans;
    }
};
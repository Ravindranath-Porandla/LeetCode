class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<long long int, int> mp;
        mp[0]++;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int req = sum - k;

            if (mp.find(req) != mp.end())
                ans += mp[req];

            mp[sum]++;
        }

        return ans;
    }
};
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long int sum = 0;
        long long int maxi = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
            mp[nums[i]]++;
        }

        int left = 0;
        int right = k - 1;
        if (mp.size() == k) {
            maxi = max(maxi, sum);
        }

        while (right < n - 1) {
            right++;
            sum += nums[right];
            mp[nums[right]]++;
            sum -= nums[left];
            mp[nums[left]]--;
            if (mp[nums[left]] == 0) {
                mp.erase(nums[left]);
            }
            left++;
            if (mp.size() == k) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};
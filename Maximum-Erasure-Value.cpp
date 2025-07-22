class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int res = 0;
        unordered_map<int, int> mp;

        while (right < n) {
            sum += nums[right];
            mp[nums[right]]++;
            while ((left <= right) && (mp[nums[right]] > 1)) {
                sum -= nums[left];
                mp[nums[left]]--;
                if (mp[nums[left]] == 0) {
                    mp.erase(nums[left]);
                }
                left++;
            }
            res = max(res, sum);
            right++;
        }
        return res;
    }
};
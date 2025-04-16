class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();

        long long pairs = 0;
        long long res = 0;
        unordered_map<int, int> mp;

        while (right < n) {
            pairs += mp[nums[right]];
            mp[nums[right]]++;

            while (pairs >= k) {
                res += (n - right);
                mp[nums[left]]--;
                pairs -= mp[nums[left]];
                left++;
            }

            right++;
        }

        return res;
    }
};
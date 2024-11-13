class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long int pro = 1;
        int ans = 0;

        while (right < n) {
            pro *= nums[right];

            while (left <= right && pro >= k) {
                pro /= nums[left];
                left++;
            }
            if (pro <= k) {
                ans += (right - left + 1);
            }

            right++;
        }
        return ans;
    }
};
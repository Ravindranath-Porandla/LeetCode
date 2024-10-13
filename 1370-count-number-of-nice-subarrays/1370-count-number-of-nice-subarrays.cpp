class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }

        int n = nums.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        int ans = 0;

        while (right < n) {
            if (nums[right] & 1) {
                cnt++;
            }

            while (cnt > k && left <= right) {
                if (nums[left] & 1) {
                    cnt--;
                }
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
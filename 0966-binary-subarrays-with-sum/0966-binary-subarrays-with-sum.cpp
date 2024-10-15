class Solution {
public:
    int solve(vector<int>& nums, int goal) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        int cnt = 0;

        while (right < n) {
            cnt += nums[right];

            while (left <= right && cnt > goal) {
                cnt -= nums[left];
                left++;
            }
            ans += (right - left + 1);
            right++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};
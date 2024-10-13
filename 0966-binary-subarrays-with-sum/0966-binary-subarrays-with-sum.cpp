class Solution {
public:
    int findSubArrays(vector<int>& nums, int goal) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int cnt = 0;

        while (right < n) {
            sum += nums[right];

            while (sum > goal && left <= right) {
                sum -= nums[left];
                left++;
            }

            cnt += right - left + 1;
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findSubArrays(nums, goal) - findSubArrays(nums, goal - 1);
    }
};
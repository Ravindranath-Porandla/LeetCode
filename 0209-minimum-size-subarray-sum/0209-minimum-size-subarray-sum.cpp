class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = 1e9;

        while (right < n) {
            sum += nums[right++];

            while (sum >= target) {
                sum -= nums[left++];
                ans = min(ans, right - left + 1);
            }
        }

        if (ans == 1e9)
            return 0;
        else
            return ans;
    }
};
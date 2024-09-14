class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int num : nums)
            maxi = max(maxi, num);

        int cnt = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};
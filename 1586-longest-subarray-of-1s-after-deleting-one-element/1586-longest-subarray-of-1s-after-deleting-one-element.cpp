class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int cnt = 0;
        int ans = INT_MIN;
        while (left <= right && right < nums.size()) {
            if (nums[right] == 0)
                cnt++;
            while (left <= right && cnt > 1) {
                if (nums[left] == 0)
                    cnt--;
                left++;
            }
            ans = max(ans, right - left);
            right++;
        }
        return ans;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        int zero_cnt = 0;

        while (left <= right && right < n) {
            if ((nums[right] == 0)) {
                zero_cnt++;
            }
            while (left <= right && zero_cnt > k) {
                if (nums[left] == 0){
                    zero_cnt--;
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
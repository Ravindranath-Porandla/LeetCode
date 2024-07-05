class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans = INT_MIN;
        int left = 0;
        int right = nums.size() - 1;

        sort(begin(nums), end(nums));
        while (left <= right) {
            ans = max(ans, nums[left] + nums[right]);
            left++;
            right--;
        }

        return ans;
    }
};
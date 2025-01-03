class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long total_sum = 0;
        long long left_sum = 0;
        int ans = 0;

        for (int num : nums) {
            total_sum += num;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            left_sum += nums[i];
            if (left_sum >= total_sum - left_sum) {
                ans++;
            }
        }

        return ans;
    }
};
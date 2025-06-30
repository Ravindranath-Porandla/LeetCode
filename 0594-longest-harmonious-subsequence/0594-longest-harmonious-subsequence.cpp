class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;

        int left = 0;
        int right = 0;

        while (right < n) {
            while ((left <= right) && ((nums[right] - nums[left]) > 1))
                left++;
            if ((nums[right] - nums[left]) == 1)
                res = max(res, right - left + 1);
            right++;
        }

        return res;
    }
};
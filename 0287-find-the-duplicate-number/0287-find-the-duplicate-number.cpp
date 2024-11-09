class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int correct = nums[i] - 1;

            if (correct < n && nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }

        return nums[n - 1];
    }
};
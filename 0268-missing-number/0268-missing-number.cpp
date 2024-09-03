class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while (i < n) {
            int correct = nums[i];
            if (correct < n && nums[i] != nums[correct]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i)
                return i;
        }
        return n;
    }
};
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        while (k--) {
            int mini = nums[0];
            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < mini) {
                    mini = nums[i];
                    idx = i;
                }
            }
            nums[idx] = nums[idx] * multiplier;
        }

        return nums;
    }
};
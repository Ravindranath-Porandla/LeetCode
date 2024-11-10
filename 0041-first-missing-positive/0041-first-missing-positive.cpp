class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n) {

            int correct = -1;
            if(nums[i] != INT_MIN){
                correct = nums[i] - 1;
            }

            if (correct < n && correct >= 0 && nums[correct] != nums[i]) {
                swap(nums[i], nums[correct]);
            } else {
                i++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + 1)) {
                return i + 1;
            }
        }

        return n + 1;
    }
};
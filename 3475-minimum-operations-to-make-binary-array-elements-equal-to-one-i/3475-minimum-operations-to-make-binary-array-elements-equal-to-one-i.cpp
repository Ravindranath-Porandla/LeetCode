class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                cnt++;
                nums[i] = 1 - nums[i];
                nums[i + 1] = 1 - nums[i + 1];
                nums[i + 2] = 1 - nums[i + 2];
            }
        }

        for (int i = n - 2; i < n; i++) {
            if (!nums[i]) {
                return -1;
            }
        }

        return cnt;
    }
};
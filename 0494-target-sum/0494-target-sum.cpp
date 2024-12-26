class Solution {
public:
    int solve(int idx, int target, vector<int>& nums) {
        if (idx < 0) {
            if (target == 0)
                return 1;
            else
                return 0;
        }

        int negative = solve(idx - 1, target - nums[idx], nums);
        int postive = solve(idx - 1, target + nums[idx], nums);

        return negative + postive;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n - 1, target, nums);
    }
};
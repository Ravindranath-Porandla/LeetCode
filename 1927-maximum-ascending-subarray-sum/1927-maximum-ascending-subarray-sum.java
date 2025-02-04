class Solution {
    public int maxAscendingSum(int[] nums) {
        int sum = nums[0];
        int res = nums[0];
        int n = nums.length;

        for (int i = 1; i < n; i++) {
            sum = nums[i] > nums[i - 1] ? sum + nums[i] : nums[i];
            res = Math.max(res, sum);
        }
        return res;
    }
}
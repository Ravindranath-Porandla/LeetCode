class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return true;
        int i = 0;

        while (i < n) {
            int bit_count = __builtin_popcount(nums[i]);
            int j = i;
            while (i < n && __builtin_popcount(nums[i]) == bit_count) {
                i++;
            }
            sort(nums.begin() + j, nums.begin() + i);
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
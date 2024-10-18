class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1;
        int j = 1;

        int n = nums.size();

        while (j < n) {
            if (nums[j] != nums[j - 1]) {
                nums[i] = nums[j];
                j++;
                i++;
            } else {
                j++;
            }
        }
        return i;
    }
};
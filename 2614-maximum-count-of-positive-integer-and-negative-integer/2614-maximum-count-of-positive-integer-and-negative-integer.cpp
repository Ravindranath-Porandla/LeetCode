class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int i = (lower_bound(nums.begin(), nums.end(), 0) - nums.begin());
        int j = (nums.end() - upper_bound(nums.begin(), nums.end(), 0));

        return max(i, j);
    }
};
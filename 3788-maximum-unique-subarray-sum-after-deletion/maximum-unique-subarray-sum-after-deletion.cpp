class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;

        while((i < n) && (nums[i] < 0)) i++;
        int sum = ((i < n) ? nums[i] : nums[n - 1]);

        for (int j = i + 1; j < n; j++)
            if (nums[j] != nums[j - 1])
                sum += nums[j];

        return sum;
    }
};
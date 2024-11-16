class Solution {
public:
    int find(int left, int right, vector<int>& nums) {
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] != nums[i - 1] + 1) {
                return -1;
            }
        }
        return nums[right];
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        int left = 0;
        int right = k - 1;

        while (right < n) {
            int x = find(left, right, nums);
            ans.push_back(x);
            right++;
            left++;
        }

        return ans;
    }
};
class Solution {
public:
    bool isPossible(int mid, vector<int> nums, int maxOperations) {
        int operations = 0;

        for (auto& num : nums) {
            if (num > mid) {
                operations += (num - 1) / mid;
            }
        }

        return maxOperations >= operations;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, nums, maxOperations)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
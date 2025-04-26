class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int left = 0;
        int right = 0;
        long long int ans = 0;
        int maxi = -1;
        int mini = -1;
        for (int right = 0, left = 0; right < nums.size(); right++) {
            int x = nums[right];
            if (x < minK || x > maxK) {
                left = right + 1;
                continue;
            }

            if (x == maxK)
                maxi = right;
            if (x == minK)
                mini = right;

            ans += max((min(maxi, mini) - left + 1), 0);
        }
        return ans;
    }
};
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;

        sort(nums.begin(), nums.end());

        vector<int> pow2(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int l = 0;
        int r = nums.size() - 1;
        int ans = 0;

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                ans = (ans + pow2[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};

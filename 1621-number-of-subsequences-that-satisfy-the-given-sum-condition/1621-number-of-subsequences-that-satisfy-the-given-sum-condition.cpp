class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        sort(nums.begin(), nums.end());
        vector<int> power(n, 1);
        
        // Precompute powers of 2 up to n modulo mod
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        long long ans = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + power[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }
        return (int)ans;
    }
};

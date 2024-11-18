class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int a = 0, b = 0;
        sort(nums.begin(), nums.end());
        vector<long long> prefix(n, nums[0]);
        for (int i = 1; i < n; i++)
            prefix[i] = nums[i] + prefix[i - 1];
        int ans = 0;
        while (b < n) {
            while ((nums[b] * (b - a + 1LL)) -
                       (prefix[b] - (a ? prefix[a - 1] : 0LL)) >
                   k) {
                a++;
            }
            ans = max(ans, b - a + 1);
            b++;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pre = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = pre;
            pre = pre * nums[i];
        }
        int post = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= post;
            post = post * nums[i];
        }
        return ans;
    }
};
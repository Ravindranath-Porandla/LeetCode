class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        vector<int> sufix(n);
        sufix[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i] * prefix[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            sufix[i] = nums[i] * sufix[i + 1];
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int x = 1;
            if (i - 1 >= 0)
                x *= prefix[i - 1];
            if (i + 1 < n)
                x *= sufix[i + 1];
            ans.push_back(x);
        }

        return ans;
    }
};
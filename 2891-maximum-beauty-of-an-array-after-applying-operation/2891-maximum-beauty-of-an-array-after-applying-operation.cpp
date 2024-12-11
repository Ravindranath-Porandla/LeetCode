class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        if(nums.size() == 1)
            return 1;

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int num : nums) {
            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        int len = maxi - mini + 2 * k + 1;

        vector<int> vec(len, 0);

        for (int num : nums) {
            int x = max(0, num - k - mini);       
            int y = min(len, num + k - mini + 1);

            vec[x]++;
            if (y < len)
                vec[y]--;
        }

        int ans = INT_MIN;

        for (int i = 1; i < len; i++) {
            vec[i] = vec[i] + vec[i - 1];
            ans = max(ans, vec[i]);
        }

        return ans;
    }
};
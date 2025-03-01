class Solution {
public:
    vector<vector<int>> dp;  // Memoization table

    int solve(int i, int j, vector<int>& nums) {
        if (i > j) return 0;  // No balloons to burst
        if (dp[i][j] != -1) return dp[i][j];

        int maxi = 0;
        for (int k = i; k <= j; k++) {

            int coins = nums[i - 1] * nums[k] * nums[j + 1] + solve(i, k - 1, nums) + solve(k + 1, j, nums);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        dp.resize(n, vector<int>(n, -1));
        return solve(1, n - 2, nums);
    }
};

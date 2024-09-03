class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        // Create a vector to store the number of ways to reach each step
        vector<int> grid(2);

        // Base cases
        grid[0] = 1; // Ways to reach step 0 (only 1 way: doing nothing)
        grid[1] = 1; // Ways to reach step 1 (only 1 way: one step of 1)

        // Iteratively calculate the number of ways to reach each step
        for (int i = 2; i <= n; ++i) {
            grid[i % 2] = grid[(i - 1) % 2] + grid[(i - 2) % 2];
        }

        return grid[n % 2];
    }
};

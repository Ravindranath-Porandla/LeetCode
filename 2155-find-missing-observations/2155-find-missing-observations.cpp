class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += rolls[i];
        }
        int rem = mean * (m + n) - sum;
        int x = rem / n;
        int y = rem % n;

        if (x <= 0 || x > 6)
            return {};
        if (x == 6 && y > 0)
            return {};

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = x;
        for (int i = 0; i < y; i++)
            ans[i]++;

        return ans;
    }
};
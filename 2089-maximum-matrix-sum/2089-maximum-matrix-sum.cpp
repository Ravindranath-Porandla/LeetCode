class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        vector<int> vec;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int cnt = 0;
        long long int ans = 0;

        for (auto row : matrix) {
            for (int col : row) {
                vec.push_back(col);
                if (col < 0) {
                    cnt++;
                    ans = ans + (col * -1);
                    maxi = max(maxi, col);
                } else {
                    mini = min(mini, col);
                    ans = ans + col;
                }
            }
        }

        if (cnt & 1) {
            if (maxi * -1 < mini)
                ans -= (maxi * -1 * 2);
            else
                ans -= (mini * 2);
        }
        return ans;
    }
};
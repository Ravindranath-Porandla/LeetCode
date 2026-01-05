class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) {
        long long sum = 0;
        int mini = INT_MAX;
        int neg_cnt = 0;
        int n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int elem = mat[i][j];
                if (elem < 0) {
                    elem = elem * -1;
                    neg_cnt++;
                }
                sum += elem;
                mini = min(mini, elem);
            }
        }
        if (neg_cnt & 1) {
            return sum - 2 * mini;
        }
        return sum;
    }
};
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> lineSweep(n + 1);

        for (int i = 0; i < n; i++) {
            while (sum + lineSweep[i] < nums[i]) {
                k++;
                if (k > queries.size()) {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1],
                    val = queries[k - 1][2];

                if (right >= i) {
                    lineSweep[max(left, i)] += val;
                    lineSweep[right + 1] -= val;
                }
            }
            sum += lineSweep[i];
        }
        return k;
    }
};
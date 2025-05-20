class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // LINE SWEEP (OR)  DIFFERENCE ARRAY TECHNIQUE
        int n = nums.size();
        vector<int> line_sweep(n, 0);

        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];

            if (r < n - 1)
                line_sweep[r + 1]--;
            line_sweep[l]++;
        }

        for (int i = 0; i < n; i++) {
            if (i > 0)
                line_sweep[i] = line_sweep[i] + line_sweep[i - 1];
            if ((nums[i] - line_sweep[i]) > 0)
                return false;
        }

        return true;
    }
};
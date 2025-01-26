class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<vector<int>> vv;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            vv.push_back({nums[i], i});
        }

        sort(vv.begin(), vv.end());

        vector<int> v(n, 0);
        vector<int> v1, v2;

        for (int i = 0; i < n; ++i) {
            if (i == 0 || vv[i][0] - vv[i - 1][0] <= limit) {
                v1.push_back(vv[i][0]);
                v2.push_back(vv[i][1]);
            } else {
                sort(v1.begin(), v1.end());
                sort(v2.begin(), v2.end());
                int k = v1.size();
                for (int j = 0; j < k; ++j) {
                    v[v2[j]] = v1[j];
                }
                v1 = {vv[i][0]};
                v2 = {vv[i][1]};
            }
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int k = v1.size();
        for (int j = 0; j < k; ++j) {
            v[v2[j]] = v1[j];
        }

        return v;
    }
};
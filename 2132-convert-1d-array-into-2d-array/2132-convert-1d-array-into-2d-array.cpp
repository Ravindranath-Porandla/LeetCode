class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res;
        if (m * n != original.size()) {
            return res;
        }

        int x = 0;
        for (int i = 0; i < m; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                temp.push_back(original[x++]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
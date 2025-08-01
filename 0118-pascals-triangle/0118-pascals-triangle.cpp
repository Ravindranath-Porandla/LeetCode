class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++) {
            vector<int> temp;
            long long val = 1;
            temp.push_back(val);
            for (int col = 1; col < row; col++) {
                val = val * (row - col);
                val = val / col;
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
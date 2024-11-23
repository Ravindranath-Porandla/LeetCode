class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for (int row = 0; row < m; row++) {
            int j = n - 1;

            for (int col = n - 1; col >= 0; col--) {
                if (box[row][col] == '#') {
                    ans[j][(m - 1) - row] = '#';
                    j--;
                }
                if (box[row][col] == '*') {
                    ans[col][(m - 1) - row] = '*';
                    j = col - 1;
                }
            }
        }
        return ans;
    }
};
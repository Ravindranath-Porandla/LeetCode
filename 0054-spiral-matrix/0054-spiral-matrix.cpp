class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (left <= right && top <= bottom) {
            if (left <= right && top <= bottom) {
                for (int col = left; col <= right; col++) {
                    ans.push_back(matrix[top][col]);
                }
                top++;
            }

            if (left <= right && top <= bottom) {
                for (int row = top; row <= bottom; row++) {
                    ans.push_back(matrix[row][right]);
                }
                right--;
            }
            if (left <= right && top <= bottom) {
                for (int col = right; col >= left; col--) {
                    ans.push_back(matrix[bottom][col]);
                }
                bottom--;
            }
            if (left <= right && top <= bottom) {
                for (int row = bottom; row >= top; row--) {
                    ans.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
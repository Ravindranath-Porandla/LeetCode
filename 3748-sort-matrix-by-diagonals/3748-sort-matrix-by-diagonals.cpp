class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
                for (int startRow = n - 1; startRow >= 0; startRow--) {
            vector<int> diagonal;
            int r = startRow, c = 0;
            while (r < n && c < n) {
                diagonal.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(diagonal.begin(), diagonal.end(), greater<int>());
            r = startRow; c = 0;
            int pos = 0;
            while (r < n && c < n) {
                grid[r][c] = diagonal[pos++];
                r++; c++;
            }
        }

        for (int startCol = 1; startCol < n; startCol++) {
            vector<int> diagonal;
            int r = 0, c = startCol;
            while (r < n && c < n) {
                diagonal.push_back(grid[r][c]);
                r++;
                c++;
            }
            sort(diagonal.begin(), diagonal.end());
            r = 0; c = startCol;
            int pos = 0;
            while (r < n && c < n) {
                grid[r][c] = diagonal[pos++];
                r++; c++;
            }
        }

        return grid;
    }
};
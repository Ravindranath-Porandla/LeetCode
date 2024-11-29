class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 0});
        int delRows[] = {-1, 1, 0, 0};
        int delCols[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                bool flag = false;
                pair<pair<int, int>, int> pair = q.front();
                q.pop();
                int row = pair.first.first;
                int col = pair.first.second;
                int time = pair.second;

                for (int i = 0; i < 4; i++) {
                    int newRow = row + delRows[i];
                    int newCol = col + delCols[i];

                    if (newRow >= 0 && newCol >= 0 && newRow < m &&
                        newCol < n && grid[newRow][newCol] <= (time + 1)) {
                        if (newRow == m - 1 && newCol == n - 1)
                            return (time + 1);
                        q.push({{newRow, newCol}, time + 1});
                    }
                }
            }
        }
        return -1;
    }
};
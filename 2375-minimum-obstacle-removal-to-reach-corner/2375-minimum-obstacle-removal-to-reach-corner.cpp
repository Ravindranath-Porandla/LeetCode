class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Directions for movement
        int del_rows[] = {0, 0, -1, 1};
        int del_cols[] = {-1, 1, 0, 0};

        // Distance array to store minimum obstacles removed
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq; // Deque for 0-1 BFS

        // Starting point
        dist[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            int row = dq.front().first;
            int col = dq.front().second;
            dq.pop_front();

            // Explore neighbors
            for (int i = 0; i < 4; i++) {
                int newRow = row + del_rows[i];
                int newCol = col + del_cols[i];

                if (newRow >= 0 && newCol >= 0 && newRow < m && newCol < n) {
                    int newRem = dist[row][col] + grid[newRow][newCol];
                    if (newRem < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newRem;
                        if (grid[newRow][newCol] == 1) {
                            dq.push_back(
                                {newRow, newCol}); // Add to back if obstacle
                        } else {
                            dq.push_front(
                                {newRow, newCol}); // Add to front if free
                        }
                    }
                }
            }
        }

        // Return the minimum obstacles to reach the bottom-right corner
        return dist[m - 1][n - 1];
    }
};

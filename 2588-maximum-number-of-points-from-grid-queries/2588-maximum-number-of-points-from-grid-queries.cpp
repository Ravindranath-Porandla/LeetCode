class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int rLen = grid.size(), cLen = grid[0].size();
        vector<pair<int, int>> queryPairs;
        for (int i = 0; i < queries.size(); i++) {
            queryPairs.emplace_back(queries[i], i);
        }
        sort(queryPairs.begin(), queryPairs.end());

        vector<int> output(queries.size(), 0);
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        vector<vector<bool>> seen(rLen, vector<bool>(cLen, false));

        pq.emplace(grid[0][0], make_pair(0, 0));
        seen[0][0] = true;
        int count = 0;
        vector<pair<int, int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (auto& [qVal, qIdx] : queryPairs) {
            while (!pq.empty() && pq.top().first < qVal) {
                auto [currVal, coord] = pq.top();
                pq.pop();
                int x = coord.first, y = coord.second;
                count++;

                for (auto& [dx, dy] : moves) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < rLen && ny >= 0 && ny < cLen &&
                        !seen[nx][ny]) {
                        pq.emplace(grid[nx][ny], make_pair(nx, ny));
                        seen[nx][ny] = true;
                    }
                }
            }
            output[qIdx] = count;
        }

        return output;
    }
};
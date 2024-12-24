class Solution {
public:
    int getDiameter(const vector<vector<int>>& graph, int nodes) {
        auto bfs = [&](int start) -> pair<int, int> {
            vector<int> dist(nodes, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int farNode = start;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int next : graph[curr]) {
                    if (dist[next] == -1) {
                        dist[next] = dist[curr] + 1;
                        q.push(next);
                        if (dist[next] > dist[farNode]) {
                            farNode = next;
                        }
                    }
                }
            }
            return {farNode, dist[farNode]};
        };
        return bfs(bfs(0).first).second;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& tree1,
                                  vector<vector<int>>& tree2) {
        int n = tree1.size() + 1, m = tree2.size() + 1;
        vector<vector<int>> g1(n), g2(m);
        for (auto& edge : tree1) {
            g1[edge[0]].push_back(edge[1]);
            g1[edge[1]].push_back(edge[0]);
        }
        for (auto& edge : tree2) {
            g2[edge[0]].push_back(edge[1]);
            g2[edge[1]].push_back(edge[0]);
        }
        int d1 = getDiameter(g1, n);
        int d2 = getDiameter(g2, m);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};
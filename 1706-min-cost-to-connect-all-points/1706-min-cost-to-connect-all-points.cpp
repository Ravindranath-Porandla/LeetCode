class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<bool> visited(n, false);
        int sum = 0;      

        pq.push({0, 0});
        int edgesUsed = 0;

        while (edgesUsed < n) {
            auto top= pq.top();
            int wt = top.first;
            int u = top.second;
            pq.pop();

            if (!visited[u]) {
                visited[u] = true;
                sum += wt;
                edgesUsed++;
            }

            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int weight = abs(points[u][0] - points[v][0]) +
                                 abs(points[u][1] - points[v][1]);
                    pq.push({weight, v});
                }
            }
        }

        return sum;
    }
};

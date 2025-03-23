class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef pair<long long, int> P;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> time(n, LLONG_MAX);
        vector<int> pathCount(n, 0);

        time[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long currDist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for (auto& ngbr : adj[currNode]) {
                int ngbrNode = ngbr.first;
                int ngbrDist = ngbr.second;

                if (currDist + ngbrDist < time[ngbrNode]) {
                    time[ngbrNode] = currDist + ngbrDist;
                    pq.push({currDist + ngbrDist, ngbrNode});
                    pathCount[ngbrNode] = pathCount[currNode];
                } else if (currDist + ngbrDist == time[ngbrNode]) {
                    pathCount[ngbrNode] =
                        (pathCount[ngbrNode] + pathCount[currNode]) % MOD;
                }
            }
        }
        return pathCount[n - 1];
    }
};
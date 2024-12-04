class Solution {
public:
    void dijkastras(vector<int>& res,
                    unordered_map<int, vector<pair<int, int>>>& adj, int src) {
        res[src] = 0;
        priority_queue < pair<int, int>,
            vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            for (auto& p : adj[node]) {
                int newNode = p.first;
                int wt = p.second;

                if (res[newNode] > d + wt) {
                    res[newNode] = d + wt;
                    pq.push({d + wt, newNode});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }
        vector<int> res(n + 1, INT_MAX);
        dijkastras(res, adj, k);

        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (res[i] == INT_MAX)
                return -1;
            maxi = max(maxi, res[i]);
        }

        return maxi;
    }
};
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> adj;
        vector<int> inDeg(n, 0);

        for (auto& x : pre) {
            int v = x[0];
            int u = x[1];
            adj[u].push_back(v);
            inDeg[v]++;
        }

        queue<int> q;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            if (!inDeg[i]) {
                q.push(i);
                res.push_back(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& v : adj[u]) {
                inDeg[v]--;
                if (!inDeg[v]) {
                    q.push(v);
                    res.push_back(v);
                }
            }
        }

        if (res.size() == n) {
            return res;
        }

        return {};
    }
};
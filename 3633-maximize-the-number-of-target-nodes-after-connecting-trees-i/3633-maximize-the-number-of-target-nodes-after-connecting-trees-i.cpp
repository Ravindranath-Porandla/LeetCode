class Solution {
public:
    int bfs(unordered_map<int, vector<int>>& adj, int node, int k) {
        queue<pair<int, int>> q;
        int len = adj.size();
        vector<int> vis(len, 0);
        vis[node] = 1;
        q.push({node, 0});
        int ans = 0;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int node = front.first;
            int level = front.second;

            if (level <= k)
                ans++;

            for (auto& n : adj[node]) {
                if (!vis[n]) {
                    vis[n] = 1;
                    q.push({n, level + 1});
                }
            }
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        unordered_map<int, vector<int>> adj1;
        unordered_map<int, vector<int>> adj2;

        for (auto& edge : edges1) {
            int u = edge[0];
            int v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for (auto& edge : edges2) {
            int u = edge[0];
            int v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        int n = adj1.size();
        int m = adj2.size();
        vector<int> ans(n, 0);

        int maxi = INT_MIN;
        for(int i = 0; i < m; i++){
            int x = bfs(adj2, i, k - 1);
            maxi = max(maxi, x);
        }

        for (int i = 0; i < n; i++) {
            ans[i] = maxi + bfs(adj1, i, k);
        }

        return ans;
    }
};

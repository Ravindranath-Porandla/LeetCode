class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<int>& vis) {
        vis[u] = 1;

        for (int& v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        int n = isConnected.size();

        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (isConnected[u][v]) {
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};
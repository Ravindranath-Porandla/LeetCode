class Solution {
public:
    pair<int, int> dfs(int node, vector<vector<int>>& adj, vector<int>& visited){
        visited[node] = 1;
        int v = 1;
        int e = adj[node].size();

        for(auto newNode : adj[node]){
            if(!visited[newNode]){
                auto pair = dfs(newNode, adj, visited);
                v += pair.first;
                e += pair.second;
            }
        }

        return {v, e};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        int cnt = 0;
        vector<vector<int>> adj(n);

        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                auto pair = dfs(i, adj, visited);
                int v = pair.first;
                int e = pair.second;

                if (v * (v - 1) == e) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
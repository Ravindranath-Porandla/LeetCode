class Solution {
public:
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, int &ans){
        for(auto pair : adj[node]){
            int newNode = pair.first;
            int dir     = pair.second;

            if(newNode != parent){
                if(dir == 1){
                    ans += 1;
                }
                dfs(newNode, node, adj, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &it : connections){
            int a = it[0];
            int b = it[1];

            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }

        int ans = 0;
        dfs(0, -1, adj, ans);
        return ans;
    }
};
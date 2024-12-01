class Solution {
public:
    bool isCycle(int u, vector<int>& vis, vector<int>& inRec,
                 unordered_map<int, vector<int>>& adj) {
        vis[u] = 1;
        inRec[u] = 1;

        for(auto &v : adj[u]){
            if(!vis[v] && isCycle(v, vis, inRec, adj)){
                return true;
            } else if(inRec[v]){
                return true;
            }
        }

        inRec[u] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;

        for (auto& x : prerequisites) {
            int v = x[0];
            int u = x[1];
            adj[u].push_back(v);
        }

        vector<int> vis(numCourses, 0);
        vector<int> inRec(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (isCycle(i, vis, inRec, adj)) {
                return false;
            }
        }

        return true;
    }
};
class Solution {
public:
    bool dfs(int node, int color, vector<int>& visited,
             vector<vector<int>>& graph) {
        visited[node] = color;

        for (auto neighbor : graph[node]) {
            if (visited[neighbor] == -1) {
                if (dfs(neighbor, !color, visited, graph) == false)
                    return false;
            } else if (visited[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                if (dfs(i, 0, visited, graph) == false)
                    return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<int> visited(n, 0);
        vector<vector<int>> list(n);

        for (auto it : edges) {
            list[it[0]].push_back(it[1]);
            list[it[1]].push_back(it[0]);
        }

        return dfs(source, destination, visited, list);
    }

    bool dfs(int src, int dest, vector<int>& visited,
             vector<vector<int>>& list) {
        if (src == dest) {
            return true;
        }
        visited[src] = 1;

        for (int newSrc : list[src]) {
            if (!visited[newSrc]) {
                if (dfs(newSrc, dest, visited, list))
                    return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& rooms) {
        visited[node] = 1;

        for (auto newNode : rooms[node]) {
            if (!visited[newNode]) {
                dfs(newNode, visited, rooms);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);

        dfs(0, visited, rooms);

        for (int v : visited) {
            if (!v)
                return false;
        }
        return true;
    }
};
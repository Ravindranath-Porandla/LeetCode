class Solution {
public:
    bool check(int currentNode, vector<int>& color, int currentColor,
               vector<vector<int>>& graph) {
        color[currentNode] = currentColor;

        for (auto& newNode : graph[currentNode]) {
            if (color[newNode] == currentColor) {
                return false;
            }
            if (color[newNode] == -1 &&
                check(newNode, color, 1 - currentColor, graph) == false) {
                return false;
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && check(i, color, 1, graph) == false) {
                return false;
            }
        }
        return true;
    }
};
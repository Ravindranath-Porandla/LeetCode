class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> topo;
        vector<int> inDeg(n, 0);

        vector<vector<int>> revGraph(n);

        for (int i = 0; i < n; i++) {
            for (auto it : graph[i]) {
                revGraph[it].push_back(i);
            }
        }

        for (int i = 0; i < n; i++) {
            for (auto it : revGraph[i]) {
                inDeg[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            topo.push_back(front);

            for (auto it : revGraph[front]) {
                inDeg[it]--;
                if (inDeg[it] == 0) {
                    q.push(it);
                }
            }
        }   

        sort(begin(topo), end(topo));

        return topo;
    }
};
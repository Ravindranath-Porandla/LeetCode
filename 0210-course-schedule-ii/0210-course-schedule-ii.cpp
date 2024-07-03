class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> topo;
        queue<int> q;

        vector<int> inDeg(n, 0);

        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                inDeg[it]++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            topo.push_back(front);

            for (auto it : adj[front]) {
                inDeg[it]--;
                if (inDeg[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(topo.size() == n)    return topo;
        else    return {};
    }
};
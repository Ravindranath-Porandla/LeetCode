class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> inDeg(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                inDeg[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
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

        if (topo.size() == numCourses)
            return true;
        return false;
    }
};
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies,
                   vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> vis(n, false);    // Visited boxes
        vector<bool> hasKey(n, false); // Whether we have key for box i
        queue<int> q;
        unordered_set<int> boxes(initialBoxes.begin(), initialBoxes.end());

        for (int b : initialBoxes) {
            if (status[b] == 1) {
                q.push(b);
                vis[b] = true;
            }
        }

        for (int b : initialBoxes) {
            if (status[b] == 0) {
                // Still track unopened boxes
                vis[b] = false;
            }
        }

        int cnt = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt += candies[u];

            // Acquire keys
            for (int k : keys[u]) {
                hasKey[k] = true;
                if (boxes.count(k) && !vis[k] && status[k] == 0) {
                    // We previously had this box but couldn't open it
                    q.push(k);
                    vis[k] = true;
                }
            }

            // Get contained boxes
            for (int b : containedBoxes[u]) {
                boxes.insert(b);
                if (!vis[b] && (status[b] == 1 || hasKey[b])) {
                    q.push(b);
                    vis[b] = true;
                }
            }
        }

        return cnt;
    }
};

class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int Find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = Find(x);
        int y_parent = Find(y);

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int cnt = 0;

        for (auto& conn : connections) {
            Union(conn[0], conn[1]);
        }

        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                cnt++;
            }
        }

        return cnt - 1;
    }
};
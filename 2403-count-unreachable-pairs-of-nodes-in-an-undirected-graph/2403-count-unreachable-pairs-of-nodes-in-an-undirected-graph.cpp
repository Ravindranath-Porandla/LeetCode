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
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int x = Find(i);
            mp[x]++;
        }

        if(mp.size() <= 1)
            return 0;

        long long cnt = 0;

        for (auto& p : mp) {
            cnt += ((long long)p.second * (n - p.second));
        }

        return (cnt / 2);
    }
};
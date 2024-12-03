class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        // int n = equations.size();

        for (auto& eq : equations) {
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';

            if (eq[1] == '=') {
                Union(x, y);
            }
        }

        for (auto& eq : equations) {
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';

            if (eq[1] == '!') {
                int x_parent = find(x);
                int y_parent = find(y);
                if (x_parent == y_parent)
                    return false;
            }
        }

        return true;
    }
};
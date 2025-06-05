class Solution {
public:
    vector<int> parent;
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26, 0);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        for (int i = 0; i < s1.size(); i++)
            performUnion(s1[i] - 'a', s2[i] - 'a');

        string res = "";

        for (char ch : baseStr)
            res.push_back(find(ch - 'a') + 'a');

        return res;
    }

private:
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void performUnion(int x, int y) {
        int px = find(x), py = find(y);
        if (py == px)
            return;
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }
};
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        unordered_set<int> st;

        for (auto& match : matches) {
            int u = match[0];
            int v = match[1];
            mp[v]++;
            st.insert(u);
            st.insert(v);
        }

        vector<int> x;
        vector<int> y;

        for (auto player : st) {
            if (mp.find(player) == mp.end()) {
                x.push_back(player);
            } else if (mp[player] == 1) {
                y.push_back(player);
            }
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        return {x, y};
    }
};
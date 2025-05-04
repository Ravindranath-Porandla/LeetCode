class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        int cnt = 0;
        unordered_map<int, int> mp;

        for (auto& d : dom) {
            if (d[0] > d[1]) {
                swap(d[0], d[1]);
            }
            int x = d[0] * 67 + d[1];
            mp[x]++;
        }

        for (auto& [d, freq] : mp) {
            cnt += (freq * (freq - 1) / 2);
        }
        return cnt;
    }
};
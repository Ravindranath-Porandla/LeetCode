class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]] = i;
        }

        vector<int> res;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, mp[s[i]]);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};
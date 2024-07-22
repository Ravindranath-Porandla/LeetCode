class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mp;
        int n = names.size() - 1;
        for (int i = 0; i <= n; i++) {
            mp[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end());
        
        for (int i = 0; i <= n; i++) {
            names[i] = mp[heights[n - i]];
        }
        return names;
    }
};
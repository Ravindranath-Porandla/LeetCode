class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size();
        int m = spaces.size();
        string res = "";
        sort(spaces.begin(), spaces.end());

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (j < m && i == spaces[j]) {
                res.push_back(' ');
                res.push_back(s[i]);
                j++;
            } else {
                res.push_back(s[i]);
            }
        }

        return res;
    }
};
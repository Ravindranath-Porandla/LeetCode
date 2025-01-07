class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> ans;
        int n = words.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    continue;

                if (words[j].find(words[i]) != string::npos) {
                    ans.insert(words[i]);
                }
            }
        }

        vector<string> res(ans.begin(), ans.end());

        return res;
    }
};
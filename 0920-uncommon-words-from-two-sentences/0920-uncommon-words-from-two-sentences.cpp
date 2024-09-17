class Solution {
public:
    void frequency(string str, unordered_map<string, int>& mp) {
        stringstream s(str);
        string word;
        while (s >> word)
            mp[word]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        frequency(s1, mp);
        frequency(s2, mp);
        vector<string> ans;
        for (auto w : mp) {
            if (w.second < 2) {
                ans.push_back(w.first);
            }
        }
        return ans;
    }
};
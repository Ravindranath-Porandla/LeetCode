class Solution {
public:
    static bool comp(pair<int, string>& a, pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (string word : words) {
            mp[word]++;
        }

        vector<pair<int, string>> temp;
        for(auto &it : mp){
            temp.push_back({it.second, it.first});
        }
        sort(temp.begin(), temp.end(), comp);
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};
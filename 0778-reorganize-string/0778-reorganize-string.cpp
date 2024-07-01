class Solution {
public:
    typedef pair<int, char> P;
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        int condition = ceil(n / 2.0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] > condition)
                return "";
        }

        priority_queue<P> pq;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                pq.push({freq[i], 'a' + i});
            }
        }

        string res = "";
        while (pq.size() >= 2) {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            res.push_back(top1.second);
            top1.first--;
            res.push_back(top2.second);
            top2.first--;

            if (top1.first != 0)
                pq.push({top1});
            if (top2.first != 0)
                pq.push({top2});
        }

        if (!pq.empty()) {
            res.push_back(pq.top().second);
        }

        return res;
    }
};
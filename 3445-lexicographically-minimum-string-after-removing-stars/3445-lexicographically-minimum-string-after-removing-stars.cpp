class Solution {
public:
    typedef pair<char, int> P;
    string clearStars(string s) {
        int n = s.size();
        priority_queue<P, vector<P>, function<bool(P, P)>> pq([](P a, P b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        });

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '*') {
                auto top = pq.top();
                pq.pop();
                s[top.second] = '*';
            } else {
                pq.push({ch, i});
            }
        }

        string res = "";
        for (char ch : s) {
            if (ch != '*')
                res.push_back(ch);
        }

        return res;
    }
};
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;

        if (a) {
            pq.push({a, 'a'});
        }
        if (b) {
            pq.push({b, 'b'});
        }
        if (c) {
            pq.push({c, 'c'});
        }

        string res = "";

        while (!pq.empty()) {
            int curCount = pq.top().first;
            int curChar = pq.top().second;
            pq.pop();

            if (res.size() >= 2 && res[res.size() - 1] == curChar &&
                res[res.size() - 2] == curChar) {
                if (pq.empty()) {
                    break;
                }
                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                res.push_back(nextChar);
                nextCount--;
                if (nextCount) {
                    pq.push({nextCount, nextChar});
                }
            } else {
                res.push_back(curChar);
                curCount--;
            }
            if (curCount) {
                pq.push({curCount, curChar});
            }
        }
        return res;
    }
};
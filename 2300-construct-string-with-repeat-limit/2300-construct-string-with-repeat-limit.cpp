class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>, vector<pair<char, int>>> pq;

        vector<int> count(26, 0);

        for (char ch : s) {
            count[ch - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i]) {
                pq.push({'a' + i, count[i]});
            }
        }

        string ans = "";

        while (!pq.empty()) {
            auto top1 = pq.top();
            pq.pop();
            char char1 = top1.first;
            int freq1 = top1.second;

            while (freq1) {
                if(ans.size() && ans[ans.size() - 1] == char1)    break;
                int temp = repeatLimit;
                while (freq1 > 0 && temp--) {
                    ans.push_back(char1);
                    freq1--;
                }

                if (freq1 && !pq.empty()) {
                    auto top2 = pq.top();
                    pq.pop();
                    char char2 = top2.first;
                    int freq2 = top2.second;

                    ans.push_back(char2);
                    freq2--;

                    if (freq2) {
                        pq.push({char2, freq2});
                    }
                }
                
            }
        }

        return ans;
    }
};
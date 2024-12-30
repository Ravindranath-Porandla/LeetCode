class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end())
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto front = q.front();
            string cur = front.first;
            int level = front.second;
            q.pop();

            if(cur == endWord){
                return level;
            }

            for (int i = 0; i < cur.size(); i++) {
                char before = cur[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch != before) {
                        cur[i] = ch;
                        if (st.find(cur) != st.end()) {
                            q.push({cur, level + 1});
                            st.erase(cur);
                        }
                    }
                }
                cur[i] = before;
            }
        }

        return 0;
    }
};
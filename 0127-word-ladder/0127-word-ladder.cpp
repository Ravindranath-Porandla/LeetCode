class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(beginWord) != st.end()) {
            st.erase(beginWord);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if (word == endWord) {
                return steps;
            }

            for (int i = 0; i < word.size(); i++) {
                char temp = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = temp;
            }
        }
        return 0;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordSet.erase(beginWord);
        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            string curWord = front.first;
            int curLength = front.second;

            if (curWord == endWord) {
                return curLength;
            }

            // Generate all possible next words by changing each character
            for (int i = 0; i < curWord.size(); ++i) {
                char originalChar = curWord[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    curWord[i] = c;

                    // Check if the generated word exists in wordSet
                    if (wordSet.find(curWord) != wordSet.end()) {
                        q.push({curWord, curLength + 1});
                        wordSet.erase(curWord); // Mark as visited
                    }
                }
                curWord[i] = originalChar; // Restore the character
            }
        }

        return 0; // No transformation sequence found
    }
};
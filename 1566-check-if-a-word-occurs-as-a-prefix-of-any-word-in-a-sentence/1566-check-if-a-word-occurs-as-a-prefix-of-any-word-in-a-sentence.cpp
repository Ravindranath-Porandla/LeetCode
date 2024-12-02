class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        for (int i = 0; i < words.size(); i++) {
            string currentWord = "";
            for (int j = 0; j < words[i].size(); j++) {
                currentWord.push_back(words[i][j]);
                if (currentWord == searchWord) {
                    return i + 1;
                }
            }
        }
        return -1;
    }
};
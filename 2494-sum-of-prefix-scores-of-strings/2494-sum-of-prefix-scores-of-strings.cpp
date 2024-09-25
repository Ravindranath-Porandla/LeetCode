struct Node {
    int count = 0;
    Node* list[26] = {nullptr};
};

class Solution {
private:
    Node* root;

public:
    Solution() { root = new Node(); }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (node->list[ch - 'a'] == nullptr) {
                node->list[ch - 'a'] = new Node();
            }
            node->list[ch - 'a']->count++;
            node = node->list[ch - 'a'];
        }
    }

    int search(const string& word) {
        Node* node = root;
        int preCount = 0;
        for (char ch : word) {
            preCount += node->list[ch - 'a']->count;
            node = node->list[ch - 'a'];
        }
        return preCount;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        for (auto& word : words) {
            insert(word);
        }

        int n = words.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int preCount = search(words[i]);
            res[i] = preCount;
        }

        return res;
    }
};
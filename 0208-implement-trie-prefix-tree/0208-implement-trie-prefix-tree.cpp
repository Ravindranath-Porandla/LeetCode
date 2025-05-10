class TrieNode{
public:
    TrieNode* c[26];
    bool isEnd;
    TrieNode(){
        for(int i = 0; i < 26; i++){
            c[i] = nullptr;
        }
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int idx =  ch - 'a';
            if(node->c[idx] == nullptr)
                node->c[idx] = new TrieNode();
            node = node->c[idx];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node->c[idx] == nullptr)
                return false;
            node = node->c[idx];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix){
            int idx = ch - 'a';
            if(node->c[idx] == nullptr)
                return false;
            node = node->c[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
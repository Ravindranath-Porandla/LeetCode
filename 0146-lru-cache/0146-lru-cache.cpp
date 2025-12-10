class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int capacity;
    LRUCache(int capacity) { this->capacity = capacity; }

    void MakeMostRecent(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            MakeMostRecent(key);
            return mp[key].second;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            MakeMostRecent(key);
        } else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            capacity--;
        }

        if (capacity < 0) {
            capacity = 0;
            mp.erase(dll.back());
            dll.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
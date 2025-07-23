class LRUCache {
    list<int> cache;
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    int cap;

public:
    LRUCache(int capacity) { cap = capacity; }

    void makeThisMostRecent(int key) {
        cache.erase(mp[key].second);
        cache.push_front(key);
        mp[key].second = cache.begin();
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        makeThisMostRecent(key);
        return mp[key].first;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].first = value;
            makeThisMostRecent(key);
        } else {
            if (mp.size() == cap) {
                int last = cache.back();
                cache.pop_back();
                mp.erase(last);
            }

            cache.push_front(key);
            mp[key] = {value, cache.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
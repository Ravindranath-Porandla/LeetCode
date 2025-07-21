import java.util.LinkedList;
import java.util.HashMap;

class Pair {
    int key;
    int val;

    Pair(int key, int val) {
        this.key = key;
        this.val = val;
    }
}

class LRUCache {
    LinkedList<Pair> list;          // Stores order of usage (most recent at tail)
    int capacity;                   // Max capacity of the cache
    HashMap<Integer, Pair> map;     // Maps key to the actual Pair object in the list

    public LRUCache(int capacity) {
        this.list = new LinkedList<>();
        this.capacity = capacity;
        this.map = new HashMap<>();
    }

    public int get(int key) {
        Pair node = map.get(key);
        if (node != null) {
            // Found: Move to end (most recently used)
            list.remove(node);      // Remove from current position
            list.addLast(node);     // Add to the end
            return node.val;        // Return the value
        }
        return -1; // Not found
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            // Case 1: Key already exists (update value and refresh usage)
            Pair node = map.get(key);
            list.remove(node);      // Remove old position
            node.val = value;       // Update the value
            list.addLast(node);     // Add to end (most recently used)
            // No need to update map, as it already points to the same 'node' object
        } else {
            // Case 2: New key
            // Check if adding this new element would exceed capacity
            if (map.size() == capacity) { // Or list.size() == capacity
                // Cache is full, evict the Least Recently Used (LRU) item
                Pair lruNode = list.removeFirst(); // Get and remove from list (LRU is at head)
                map.remove(lruNode.key);           // Remove from map
            }

            // Create new Pair and add to cache
            Pair newNode = new Pair(key, value);
            list.addLast(newNode); // Add to list (MRU is at tail)
            map.put(key, newNode); // Add to map
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
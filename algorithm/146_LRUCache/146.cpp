/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

class LRUCache {
public:
    LRUCache(int capacity) : size(capacity) {
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return -1;
        } else {
            CacheEntry* entry = it->second;
            _list.remove(entry);
            _list.set_head(entry);
            return entry->value;
        }
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            CacheEntry* entry = it->second;
            entry->value = value;
            _list.remove(entry);
            _list.set_head(entry);
        } else {
            // not found. new insert
            if (cacheMap.size() == size) {
                // need  to evict one entry first
                evictTail();
                CacheEntry* entry = new CacheEntry(key, value);
                _list.insert_as_head(entry);
                cacheMap.insert(key, entry);
            }
        }
    }


private:
    void evictTail() {
        CacheEntry* entry = _list.tail();
        _list.remove_tail();
        //
        auto it = cacheMap.find(entry->key);
        cacheMap.erase(it);
    }
    struct CacheEntry {
        int key;
        int value;
        CacheEntry(int k, int v) : key(k), value(v) {}
    };

    int size;
    struct DList {
        CacheEntry *head;
        CacheEntry *tail;
        CacheEntry *prev;
        CacheEntry *next;
        DList(): head(NULL), tail(NULL), prev(NULL), next(NULL) {}

        void set_head(CacheEntry* entry) {
            if (!head) {
                assert(!tail);
                head = tail = entry;
            } else {
                entry->next = head;
                head->prev = entry;
                head = entry;
            }
        }

        void remove_tail() {
            
        }


    };

    DList _list;

    map<int, CacheEntry*> cacheMap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
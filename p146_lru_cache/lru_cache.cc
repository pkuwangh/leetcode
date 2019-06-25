/**
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 It should support the following operations: get and put.

 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

 * The cache is initialized with a positive capacity.

 * Follow up:
 * Could you do both operations in O(1) time complexity?
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
  public:
    LRUCache(int capacity) :
        size_ (capacity)
    {
    }

    void touchMru(int key) {
        auto iter = lookup_table_[key].second;
        lru_chain_.erase(iter);
        lru_chain_.push_front(key);
        lookup_table_[key].second = lru_chain_.begin();
    }

    int get(int key) {
        if (lookup_table_.count(key) > 0) {
            touchMru(key);
            return lookup_table_[key].first;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (lookup_table_.count(key) > 0) {
            touchMru(key);
            lookup_table_[key].first = value;
        } else {
            // victimize if necessary
            if (lru_chain_.size() == size_) {
                int vic_key = lru_chain_.back();
                lru_chain_.pop_back();
                lookup_table_.erase(vic_key);
            }
            // add new element
            lru_chain_.push_front(key);
            lookup_table_[key] = std::make_pair(value, lru_chain_.begin());
        }
    }

  private:
    const uint32_t size_;
    std::list<int> lru_chain_;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> lookup_table_;
};


int main() {
    LRUCache* cache = new LRUCache(2);

    cache->put(1, 1);
    cache->put(2, 2);
    std::cout << cache->get(1) << std::endl;      // returns 1
    cache->put(3, 3);    // evicts key 2
    std::cout << cache->get(2) << std::endl;       // returns -1 (not found)
    cache->put(4, 4);    // evicts key 1
    std::cout << cache->get(1) << std::endl;       // returns -1 (not found)
    std::cout << cache->get(3) << std::endl;       // returns 3
    std::cout << cache->get(4) << std::endl;       // returns 4

    return 0;
}

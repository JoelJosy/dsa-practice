// 146 LRU Cache
// https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
    int capacity;
    list<pair<int, int>> dll; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> map;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (map.find(key) == map.end())
            return -1;

        // Move node to front
        dll.splice(dll.begin(), dll, map[key]);
        return map[key]->second;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            dll.splice(dll.begin(), dll, map[key]);
            map[key]->second = value;
        } else {
            if (dll.size() == capacity) {
                int lruKey = dll.back().first;
                map.erase(lruKey);
                dll.pop_back();
            }
            dll.push_front({key, value});
            map[key] = dll.begin();
        }
    }
};
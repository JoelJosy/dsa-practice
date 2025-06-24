# Time Based Key-Value Store
# https://leetcode.com/problems/time-based-key-value-store/

class TimeMap {
public:
    unordered_map<string, map<int, string>> map;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        
        auto it = map[key].upper_bound(timestamp);
        if (it == map[key].begin()) return ans;
        it--;
        ans = it->second;
        return ans;
    }   
};


/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
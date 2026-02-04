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


//  Binsearch soln

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";

        auto &arr = mp[key];
        int l = 0, r = arr.size() - 1;
        string ans = "";

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid].first <= timestamp) {
                ans = arr[mid].second;   // valid candidate
                l = mid + 1;             // try to find later timestamp
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
// T: O(nlogn)
// S: O(n)
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> events;
        for (auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // start
            events.push_back({b[1], b[2]});  // end
        }
        sort(events.begin(), events.end());

        multiset<int> active = {0}; // so rbegin() never fails
        int prevmax = 0;

        int i = 0, n = events.size();
        while (i < n) {
            int x = events[i].first;
            // process all events at this same x
            while (i < n && events[i].first == x) {
                int h = events[i].second;
                if (h < 0) active.insert(-h);          // start
                else active.erase(active.find(h));      // end
                i++;
            }
            int currmax = *active.rbegin();
            if (currmax != prevmax) {
                res.push_back({x, currmax});
                prevmax = currmax;
            }
        }
        return res;
    }
};

// go through each x where building starts/ends
// tallest determines skyline
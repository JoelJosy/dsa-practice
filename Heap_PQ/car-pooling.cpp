// T: O(n)
// S: O(1)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        vector<int> diff(1001, 0);

        for (auto& t: trips) {
            int ppl = t[0];
            int start = t[1];
            int end = t[2];

            diff[start] += ppl;
            diff[end] -= ppl;
        }
        
        int passengers = 0;
        for (int i = 0; i < 1001; i++) {
            passengers += diff[i];
            if (passengers > cap) return false;
        }
        return true;
    }
};


// Heap Soln
// T: O(nlogn)
// S: O(n)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        // sort by pickup location
        sort(trips.begin(), trips.end(), 
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // dropoff location, curr passengers
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        int dist = 0;
        int passengers = 0;
        int i = 0;
        while (i < trips.size()) {
            dist = trips[i][1];

            // dropoff passengers if any
            while (!pq.empty() && pq.top().first <= dist) {
                auto [drop, pass] = pq.top(); pq.pop();
                passengers -= pass;
            }

            // pickup new passengers
            passengers += trips[i][0];
            if (passengers > cap) {
                return false;
            }
            pq.push({trips[i][2], trips[i][0]});
            i++;
        }
        return true;
    }
};
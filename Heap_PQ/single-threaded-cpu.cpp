// T: O(nlogn)
// S: O(n) 
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> res;
        
        priority_queue<
            pair<int, int>, 
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }

        // sort by enqueue time
        sort(tasks.begin(), tasks.end());
        
        int n = tasks.size();
        int i = 0;
        long long time = 0;
        while (i < n || !pq.empty()) {
            if (pq.empty()) {
                time = max(time, (long long) tasks[i][0]);
            }

            while (i < n && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            auto [processing, idx] = pq.top(); pq.pop();
            res.push_back(idx);
            time += processing;
        }
        return res;
    }
};


// heap -> {processing time, i} 
// simulate cpu
// enqueue curr task
// skip to time it ends
// check queue, process with least time
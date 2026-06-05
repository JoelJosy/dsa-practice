// Time: O(nlogn + mlogm)
// Space: O(n+m)

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        // query, index
        vector<pair<int,int>> qs;
        for (int i = 0; i < m; i++)
            qs.push_back({queries[i], i});

        sort(intervals.begin(), intervals.end());
        sort(qs.begin(), qs.end());

        // heap -> {size, end}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> res(m);
        int i = 0;
        for (auto& [q, idx]: qs) {
            while (i < n && intervals[i][0] <= q) {
                int len = intervals[i][1] - intervals[i][0] + 1;
                pq.push({len, intervals[i][1]});
                i++;
            }

            while (!pq.empty() && pq.top().second < q) {
                pq.pop();
            }

            if (!pq.empty())
                res[idx] = pq.top().first;
            else res[idx] = -1;
        }
        return res;
    }
};


// sort queries and intervals
// iterate through queries
// push interval into minheap if start <= query
// pop if end < query
// soln is heap top, append to res
// track original query indices
// Dijkstra's algorithm
// T: O(ElogV)
// S: O(V+E)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n); // dst, weight

        for (auto& edge: times) {
            int u = edge[0], v = edge[1], t = edge[2];
            graph[u-1].push_back({v-1, t});
        }

        vector<int> dist(n, INT_MAX);
        // time, node
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>,
                       greater<>> pq;
        
        
        pq.push({0, k-1});
        unordered_set<int> visited;
        while (!pq.empty()) {
            auto [mintime, minnode] = pq.top();
            pq.pop();

            if (visited.count(minnode)) continue;

            visited.insert(minnode);
            dist[minnode] = mintime;
            
            for (auto& [ndst, ntime]: graph[minnode]) {
                if (!visited.count(ndst))
                    pq.push({mintime+ntime, ndst});
            }

        }

        int res = *max_element(dist.begin(), dist.end());
        return (res == INT_MAX) ? -1 : res;
    }
};


// Slighly more space efficient Dijkstra's (less heap size, no visited set)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n);

        for (auto& e : times) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            int w = e[2];
            graph[u].push_back({v, w});
        }

        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<>
        > pq;

        pq.push({0, k - 1});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // skip outdated entries
            if (d > dist[node]) continue;

            for (auto [nei, w] : graph[node]) {
                if (dist[nei] > d + w) {
                    dist[nei] = d + w;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int ans = 0;
        for (int d : dist) {
            if (d == INT_MAX) return -1;
            ans = max(ans, d);
        }

        return ans;
    }
};

// Kruskal's
// T: O(n * m * log(n * m))
// S: O(n * m)
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rank[a] < rank[b]) swap(a, b);

        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<tuple<int,int,int>> edges;

        vector<pair<int,int>> dir = {
            {0,1},{1,0}
        };

        // Build edges (only right + down to avoid duplicates)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto [dx, dy] : dir) {
                    int ni = i + dx;
                    int nj = j + dy;

                    if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                        continue;

                    int w = abs(heights[i][j] - heights[ni][nj]);

                    int u = i * m + j;
                    int v = ni * m + nj;

                    edges.push_back({w, u, v});
                }
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n * m);

        int start = 0;
        int end = (n * m) - 1;

        for (auto [w, u, v] : edges) {
            dsu.unite(u, v);

            if (dsu.find(start) == dsu.find(end))
                return w;
        }

        return 0;
    }
};


// Dijkstra's
// T: O(n * m * log(n * m))
// S: O(n * m)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // max effort, i, j
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<pair<int, int>> dirns = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, 0, 0});
    
        while (!pq.empty()) {
            auto [eff, i, j] = pq.top(); pq.pop();

            if (i == n-1 && j == m-1)
                return eff;

            if (eff > dist[i][j]) continue;

            for (auto [r, c]: dirns) {
                int nr = i + r;
                int nc = j + c;
                if (nr >= n || nr < 0 || nc >= m || nc < 0 ) {
                     continue;
                }

                int newEff = max(eff, abs(heights[i][j] - heights[nr][nc]));
                if (dist[nr][nc] > newEff) {
                    dist[nr][nc] = newEff;
                    pq.push({newEff, nr, nc});
                }   
            }
        }
        return -1;
    }
};
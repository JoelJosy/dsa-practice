// DSU
// At time T, what cells are passable
// stop when 0,0 is connected to n-1, n-1
class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) return false;

        if (rank[p1] < rank[p2]) swap(p1, p2);

        parent[p2] = p1;
        rank[p1] += rank[p2];
        return true;
    }

};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<tuple<int,int,int>> cells; // {height, r, c}

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cells.push_back({grid[r][c], r, c});
            }
        }

        sort(cells.begin(), cells.end());

        DSU dsu(n*n);

        vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        for (auto& [t, r, c] : cells) {
            for (auto& [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 &&
                    nc < n && grid[nr][nc] <= t) {
                    dsu.unite(r * n + c, nr * n + nc);
                }
            }

            if (dsu.find(0) == dsu.find(n*n - 1)) return t;
        }
        return -1;
    }
};


// Dijkstra's
// T: O(n^2logn)
// S: O(n^2)
// in heap, store max height on the path up to (r,c)
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<>
        > pq;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        // {time_needed, row, col}
        pq.push({grid[0][0], 0, 0});

        vector<pair<int,int>> dirs = {
            {0,1}, {0,-1}, {1,0}, {-1,0}
        };

        while (!pq.empty()) {
            vector<int> popped = pq.top();
            int time = popped[0], r = popped[1], c = popped[2];
            pq.pop();

            if (visited[r][c]) continue;
            visited[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return time;

            for (auto& [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                if (nr < 0 || nr >= n ||
                    nc < 0 || nc >= n ||
                    visited[nr][nc]) {
                    continue;
                }
                int newTime = max(time, grid[nr][nc]);
                pq.push({newTime, nr, nc});
            }
        }

        return -1;
    }
};


// T: O(n^2logn)
// S: O(n^2)
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        set<pair<int, int>> visited;
        priority_queue<vector<int>, vector<vector<int>>,
                        greater<>> pq;

        int res = 0;
        // time so far, r, c
        pq.push({grid[0][0], 0, 0});
        visited.insert({0, 0});

        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        while (!pq.empty()) {
            vector<int> popped = pq.top();
            int t = popped[0], r = popped[1], c = popped[2];
            pq.pop();

            res = max(res, t);
            if (r == n - 1 && c == n - 1) return res;

            for (auto& d: directions) {
                int nr = d[0] + r;
                int nc = d[1] + c;
                if (nr < n && nc < n &&
                    nr >= 0 && nc >= 0 &&
                    !visited.count({nr, nc})) {
                    pq.push({grid[nr][nc], nr, nc});
                    visited.insert({nr, nc});
                }
            }
        }

        return res;
    }
};

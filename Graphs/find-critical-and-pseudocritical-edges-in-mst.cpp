// T: O(ElogE + E^2 alpha(V))
// S: O(V)
class DSU {
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int u, int v) {
        int p1 = find(u);
        int p2 = find(v);

        if (p1 == p2) return false;

        if (size[p1] < size[p2]) swap(p1, p2);

        size[p1] += size[p2];
        parent[p2] = p1;
        return true;
    }
};

class Solution {
public:
    int kruskals(vector<vector<int>>& edges, int v, int ignoreIdx, int forceIdx) {
        DSU dsu(v);
        int weight = 0;
        int edgeCount = 0;

        if (forceIdx != -1) {
            weight += edges[forceIdx][2];
            edgeCount++;
            dsu.unite(edges[forceIdx][1], edges[forceIdx][0]);
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == ignoreIdx || i == forceIdx) continue;
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if (dsu.unite(u, v)) {
                weight += w;
                edgeCount++;
            }
        }

        // disconnected graph
        if (edgeCount != v-1) return -1;
        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // track original indices
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), 
            [](auto &a, auto &b) {
                return a[2] < b[2];
            });

        int baseWeight = kruskals(edges, n, -1, -1);
        
        vector<vector<int>> res;
        vector<int> critical;
        vector<int> pseudo;
        for (int i = 0; i < edges.size(); i++) {
            // remove edge and form mst
            int removedWeight = kruskals(edges, n, i, -1);
            // if disconnected or greater weight => critical
            if (removedWeight == -1 || removedWeight > baseWeight) {
                critical.push_back(edges[i][3]);
            }  else {
                // force edge and form mst
                int forcedWeight = kruskals(edges, n, -1, i);
                if (forcedWeight == baseWeight)
                    pseudo.push_back(edges[i][3]);
            }
        }
        res.push_back(critical);
        res.push_back(pseudo);
        return res;
    }
};
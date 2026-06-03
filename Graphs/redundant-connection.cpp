// DFS Way:
// T: O(n^2) for n nodes O(E*(V+E))
// S: O(n) for n nodes O(V+E)
// Its a tree, ONE edge added that made it a cycle. So simulate tree making.
// Construct graph at each edge iteration
// Before adding edge, check if connected with dfs
// If connected -> return iteration
// Else -> add to graph


class Solution {
public:
    bool dfs(int src, int dst, vector<vector<int>>& graph, vector<int>& visited) {
        if (src == dst) return true;

        visited[src] = 1;
        for (int neigh: graph[src]) {
            if (visited[neigh] != 1)
                if (dfs(neigh, dst, graph, visited))
                    return true;
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // nodes from 1 to n
        vector<vector<int>> graph(n+1);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            vector<int> visited(n + 1, 0);

            if (dfs(u, v, graph, visited)) 
                return edge;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
};


// Union Find 
// T: O(n)
// S: O(n)

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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);

        for (auto& e: edges) {
            int n1 = e[0];
            int n2 = e[1];

            if (!dsu.unite(n1, n2)) return e;
        }
        return {};
    }
};






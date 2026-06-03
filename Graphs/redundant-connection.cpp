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




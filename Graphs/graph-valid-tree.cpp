// Time: O(V+E)
// Space: O(V+E)

class Solution {
public:
    bool dfs(int parent, int curr, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
        // cycle detected
        if (visited.find(curr) != visited.end()) return false;

        visited.insert(curr);

        for (int neighbor: graph[curr]) {
            if (neighbor == parent) continue;
            
            if (!dfs(curr, neighbor, graph, visited))
                return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;

        unordered_map<int, vector<int>> graph;
        for (vector<int> e: edges) {
            int n1 = e[0];
            int n2 = e[1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        unordered_set<int> visited;
        if (!dfs(-1, 0, graph, visited))
            return false;
        
        // return if all connected
        return visited.size() == n;
    }
};

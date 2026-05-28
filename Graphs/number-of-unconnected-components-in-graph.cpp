class Solution {
public:
    void dfs(int curr, vector<vector<int>>& graph, unordered_set<int>& visited) {
        // if cycle, return
        if (visited.count(curr)) return;

        visited.insert(curr);

        vector<int> neighbors = graph[curr];
        for (int n: neighbors) {
            dfs(n, graph, visited);
        }
        return;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (vector<int> e: edges) {
            int n1 = e[0];
            int n2 = e[1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }
        unordered_set<int> visited;

        int res = 0;
        for (int i = 0; i < n; i++) {
            // if unvisited, diff component
            if (visited.find(i) == visited.end()) res++;
            else continue;

            dfs(i, graph, visited);
        }
        return res;
    }
};

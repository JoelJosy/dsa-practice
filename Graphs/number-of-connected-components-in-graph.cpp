// T: O(V+E)
// S: O(V+E)

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


// Union Find
// for every successful union, number of diff components decreases
// T: O(V+E α(V)) or O(V+E)
// S: O(V)

class Solution {
public:
    vector<int> parent;
    vector<int> rank;


    int find(int node) {
        while (parent[node] != node) {
            // for optimization
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    bool unionSets(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) return false;

        if (rank[p1] < rank[p2]) {
            swap(p1, p2);
        }
        parent[p2] = p1;
        rank[p1] += rank[p2];
        return true;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n, 1);


        int res = n;
        for (auto& e: edges) {
            int u = e[0], v = e[1];
            if (unionSets(u, v))
                res--;
        }

        return res;
    }
};

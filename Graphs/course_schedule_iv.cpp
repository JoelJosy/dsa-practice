// Optimal (Floyd Warshall)
// T: O(V^3 + E + Q)
// S: O(V^2)
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // adj[i][j], i->j is reachable
        vector<vector<bool>> adj(numCourses, vector<bool>(numCourses, false));

        vector<bool> res;
        for (auto& pre : prerequisites) {
            adj[pre[0]][pre[1]] = true;
        }

        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
                }
            }
        }
        for (auto& q : queries) {
            res.push_back(adj[q[0]][q[1]]);
        }

        return res;
    }
};


// DFS for each node, track reachable nodes, memoize
// T: O(V * (V + E))
// S: O(V²)
class Solution {
public:
    vector<vector<int>> graph;
    vector<unordered_set<int>> reachable;
    vector<bool> computed;

    unordered_set<int>& dfs(int u) {
        if (computed[u]) return reachable[u];

        computed[u] = true;

        for (int v : graph[u]) {
            reachable[u].insert(v);

            auto& child = dfs(v);
            reachable[u].insert(child.begin(), child.end());
        }

        return reachable[u];
    }

    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries
    ) {
        graph.resize(numCourses);
        reachable.resize(numCourses);
        computed.assign(numCourses, false);

        for (auto& p : prerequisites)
            graph[p[0]].push_back(p[1]);

        for (int i = 0; i < numCourses; i++)
            dfs(i);

        vector<bool> ans;
        for (auto& q : queries)
            ans.push_back(reachable[q[0]].count(q[1]));

        return ans;
    }
};
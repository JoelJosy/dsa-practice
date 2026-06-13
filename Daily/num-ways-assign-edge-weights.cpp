// Number of Ways to Assign Edge Weights I
// T: O(n)
// S: O(n)
class Solution {
public:
    int depth(vector<vector<int>>& adj, int node, int par) {
        int d = 0;
        for (auto &child : adj[node]) {
            if (child == par) continue;
            d = max(d, 1 + depth(adj, child, node));
        }
        return d;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int d = depth(adj, 1, -1);

        long long res = 1;
        for (int i = 1; i < d; i++) {
            res = (res*2) % (int)(1e9+7);
        }
        return res;
    }
};

// d is depth
// if we freely choose d-1 edge weights 
// well have 2^(d-1) choices
// first edge no choice, depends on other choices
// must make sure no of 1 is odd, for cost to be odd

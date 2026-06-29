// T: O(Q * (V+E))
// S: O(V+E)
class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    double dfs(string src, string dst, unordered_set<string>& visited, double res) {
        if (src == dst) {
            return res;
        }

        visited.insert(src);
        for (auto& [d, val]: adj[src]) {
            if (visited.count(d)) continue;

            double ans = dfs(d, dst, visited, res * val);
            if (ans != -1) return ans;
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // O(E)
        for (int i = 0; i < values.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            double inv = 1.0 / val;

            adj[u].push_back({v, val});
            adj[v].push_back({u, inv});
        }
        vector<double> res;
        // O(Q)
        for (auto& q: queries) {
            string u = q[0];
            string v = q[1];
            
            if (!adj.count(u) || !adj.count(v)) {
                res.push_back(-1.0);
                continue;
            }

            if (u == v) {
                res.push_back(1.0);
                continue;
            }
            // O(V+E)
            unordered_set<string> visited;
            double ans = dfs(u, v, visited, 1.0);
            res.push_back(ans);
        }
        return res;
    }
};

// DSU
// T:
// S: 
class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    string find(string x) {
        if (parent[x] == x) return x;

        string p = parent[x];
        string root = find(p);

        // compress path + fix ratio
        weight[x] *= weight[p];
        parent[x] = root;

        return parent[x];
    }

    void unite(string a, string b, double val) {
        if (!parent.count(a)) {
            parent[a] = a;
            weight[a] = 1.0;
        }
        if (!parent.count(b)) {
            parent[b] = b;
            weight[b] = 1.0;
        }

        string rootA = find(a);
        string rootB = find(b);

        if (rootA == rootB) return;

        // attach A under B
        parent[rootA] = rootB;

        // adjust weight:
        // we want: a / b = val to hold
        weight[rootA] = val * (weight[b] / weight[a]);
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries
    ) {
        for (int i = 0; i < equations.size(); i++) {
            unite(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> ans;

        for (auto &q : queries) {
            string a = q[0], b = q[1];

            if (!parent.count(a) || !parent.count(b)) {
                ans.push_back(-1.0);
                continue;
            }

            string rootA = find(a);
            string rootB = find(b);

            if (rootA != rootB) {
                ans.push_back(-1.0);
            } else {
                ans.push_back(weight[a] / weight[b]);
            }
        }

        return ans;
    }
};
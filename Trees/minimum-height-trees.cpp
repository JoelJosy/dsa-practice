// T: O(n)
// S: O(n)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);

        for (auto& e: edges) {
            degree[e[0]]++;
            graph[e[0]].push_back(e[1]);
            degree[e[1]]++;
            graph[e[1]].push_back(e[0]);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) 
                q.push(i);
        }

        int remaining = n;
        while (remaining > 2) {
            int levelsize = q.size();
            remaining -= levelsize;

            for (int i = 0; i < levelsize; i++) {
                int leaf = q.front();
                q.pop();

                for (int neighbor : graph[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

// find center of tree, that must be a good root
// go inwards, prune leaves at each step
// remaining 1 or 2 nodes are centers
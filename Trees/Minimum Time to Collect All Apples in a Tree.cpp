// DFS
// T: O(n)
// S: O(n)
class Solution {
public:
    unordered_map<int, vector<int>> tree;
    int time = 0;
    bool dfs(vector<bool>& hasApple, int node, int parent) {
        bool subtreeApple = hasApple[node];
        for (int child: tree[node]) {
            if (child == parent) continue;

            if (dfs(hasApple, child, node)) {
                subtreeApple = true;
                time += 2;
            }
        }
        
        // true if this subtree contains at least one apple.
        return subtreeApple;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for (auto& e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        dfs(hasApple, 0, -1);
        return time;
    }
};
// check if each node's subtree has an apple or not
// if yes, contribute 2s to traverse edge
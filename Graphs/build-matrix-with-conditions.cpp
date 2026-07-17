// Topological Sort
// T: O(k + R + C)
// S: O(k + R + C) k^2 if including output
class Solution {
public:
    // int -> nums below it
    unordered_map<int, vector<int>> graph;
    vector<int> indegree;

    bool topoSort(vector<int>& posmap, int k) {
        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int idx = 0;
        int processed = 0;
        while (!q.empty()) {
            int num = q.front(); q.pop();
            processed++;
            posmap[num] = idx;
            idx++;

            for (int neigh: graph[num]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        return processed == k;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> res(k, vector<int>(k, 0));
        vector<int> rowpos(k + 1);
        vector<int> colpos(k + 1);
        indegree.resize(k+1, 0);

        for (auto& cond: rowConditions) {
            graph[cond[0]].push_back(cond[1]);
            indegree[cond[1]]++;
        }
        bool nocycles = topoSort(rowpos, k);

        graph.clear();
        indegree.assign(k+1, 0);
        for (auto& cond: colConditions) {
            graph[cond[0]].push_back(cond[1]);
            indegree[cond[1]]++;
        }
        nocycles = nocycles && topoSort(colpos, k);

        if (!nocycles) 
            return {};

        for (int i = 1; i <= k; i++) {
            res[rowpos[i]][colpos[i]] = i;
        }
        return res;
    }
};
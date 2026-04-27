class Solution {
public:
    bool dfs(int crs, unordered_set<int>& visiting, unordered_set<int>& visited, unordered_map<int, vector<int>>& mp, vector<int>& res) {
        if (visiting.count(crs)) return false; // found cycle
        if (visited.count(crs)) return true; // alr checked, safe

        visiting.insert(crs);
        for (auto p: mp[crs]) {
            if (!dfs(p, visiting, visited, mp, res)) return false;
        }
        visiting.erase(crs);
        visited.insert(crs);
        res.push_back(crs);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;

        for (auto& p: prerequisites) {
            mp[p[0]].push_back(p[1]);
        }

        unordered_set<int> visiting;
        unordered_set<int> visited;
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, visiting, visited, mp, res)) return {};
        }
        return res;
    }
};


// Kahns Algorithm

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course); // prereq → course
            indegree[course]++;
        }

        // Queue for nodes with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;

        // BFS
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        // If not all courses processed → cycle
        if (order.size() != numCourses) return {};

        return order;
    }
};


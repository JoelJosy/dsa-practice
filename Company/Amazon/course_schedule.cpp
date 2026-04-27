class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& mp, int crs, unordered_set<int>& visiting, unordered_set<int>& visited) {
        if (visiting.count(crs)) return false;
        if (visited.count(crs)) return true;

        visiting.insert(crs);
        for (int p: mp[crs]) {
            if (!dfs(mp, p, visiting, visited)) return false;
        }
        visiting.erase(crs);
        visited.insert(crs);
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // crs, deps
        unordered_map<int, vector<int>> mp;
        for (auto& p: prerequisites) {
            mp[p[0]].push_back(p[1]);
        }

        unordered_set<int> visiting;
        unordered_set<int> visited;

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(mp, i, visiting, visited)) return false;
        }   
        return true;
    }
};

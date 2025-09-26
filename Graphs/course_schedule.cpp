// 207. Course Schedule
// https://leetcode.com/problems/course-schedule/

class Solution {
public:

    bool dfs(int crs, unordered_map<int, vector<int>>& preMap, unordered_set<int>& visiting) {
        if (visiting.count(crs)) return false;
        if (preMap[crs].empty()) return true;

        visiting.insert(crs);
        for (int pre: preMap[crs]) {
            if (!dfs(pre, preMap, visiting)) return false;
        }
        visiting.erase(crs);
        preMap[crs].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>preMap;

        for (const auto& prereq: prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        unordered_set<int> visiting;

        // {0 : [1, 2], 1: [0, 2]}
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, preMap, visiting)) return false;
        }
        return true;
    }
};

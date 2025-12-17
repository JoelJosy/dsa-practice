// 210. Course Schedule II
// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereqs;
        unordered_set<int> cycles;
        unordered_set<int> visited;

        for (auto& pair: prerequisites) {
            prereqs[pair[0]].push_back(pair[1]);
        }

        vector<int> res;

        for (int crs = 0; crs<numCourses; crs++) {
            if (!dfs(crs, prereqs, cycles, visited, res)) {
                return {};
            }
        }

        return res;
    }
private:
    bool dfs(int crs, unordered_map<int, vector<int>>& prereqs, unordered_set<int>& cycles, unordered_set<int>& visited, vector<int>& res) {

        if (cycles.count(crs)) return false;
        if (visited.count(crs)) return true;

        cycles.insert(crs);

        if (prereqs.count(crs)) {
            for (int pre : prereqs[crs]) {
                if (!dfs(pre, prereqs, cycles, visited, res)) {
                    return false;
                }
            }
        }

        cycles.erase(crs);
        visited.insert(crs);
        res.push_back(crs);
        return true;
    }
};
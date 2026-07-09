// BFS
// T: O(n)
// T: O(n)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        // visited indexes
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push({start});

        while (!q.empty()) {
            int curr = q.front(); q.pop();

            if (visited[curr]) continue;
            visited[curr] = true;

            int jump = arr[curr];
            if (jump == 0) return true;

            if (curr + jump < n) 
                q.push(curr+jump);
            if (curr - jump >= 0) 
                q.push(curr-jump);
        }
        return false;
    }
};

// DFS
// T: O(n)
// T: O(n)
class Solution {
public:
    // visited indexes
    vector<bool> visited; 
    bool dfs(int curr, vector<int>& arr) {
        if (visited[curr]) return false;
        visited[curr] = true;

        int jump = arr[curr];
        if (jump == 0) return true;

        if (curr + jump < arr.size()) {
            if (dfs(curr + jump, arr)) 
                return true;
        }

        if (curr - jump >= 0) {
            if (dfs(curr - jump, arr))
                return true;
        }
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        visited.resize(arr.size(), false);
        return dfs(start, arr);
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0]=1;
        int dist = 1;

        vector<pair<int,int>> dirs = {
            {1,0},{-1,0},{0,1},{0,-1},
            {1,1},{1,-1},{-1,1},{-1,-1}
        };

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r,c] = q.front();
                q.pop();

                if (r == n-1 && c == n-1)
                    return dist;
            
                for (auto& d: dirs) {
                    int nr = r + d.first;
                    int nc = c + d.second;
                    if (nr >= n || nc >= n || nr < 0 || nc < 0 || 
                    grid[nr][nc]==1) {
                        continue;
                    }

                    if (grid[nr][nc]==0) {
                        q.push({nr, nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
            dist++;

        }
        return -1;
    }
};
// T: O(V+E)
// S: O(V);

class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) 
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) return false;

        if (rank[p1] < rank[p2]) swap(p1, p2);

        parent[p2] = p1;
        rank[p1] += rank[p2];
        return true;
    }

};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        int res = n;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    if (dsu.unite(i, j)) res--;
                }
            }
        }
        return res;
    }
};
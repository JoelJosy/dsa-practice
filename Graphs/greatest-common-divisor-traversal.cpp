// Union Find
// T: O(n * root(max number))
// S: O(n)

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
    vector<int> getFactors(int x) {
        vector<int> res;
        int d = 2;
        while (d * d <= x) {
            if (x % d == 0) {
                res.push_back(d);
                while (x % d == 0)
                    x /= d;
            }
            d++;
        }
        if (x > 1)
            res.push_back(x); 
        return res;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        DSU dsu(n);
        // prime factor -> prev idx with factor
        unordered_map<int, int> prevPrime;

        for (int i = 0; i < n; i++) {
            // O(root num)
            vector<int> factors = getFactors(nums[i]);

            for (int f: factors) {
                if (!prevPrime.count(f)) {
                    prevPrime[f] = i;
                } else {
                    dsu.unite(prevPrime[f], i);
                }
            }
        }

        int root = dsu.find(0);

        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root)
                return false;
        }
        return true;
    }
};
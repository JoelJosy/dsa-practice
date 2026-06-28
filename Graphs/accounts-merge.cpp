// T: O(E + E + ElogE) => O(ElogE)
// S: O(E)
// N -> no of accounts
// M -> avg emails per account
// E -> N*M -> total emails
class DSU {
public: 
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n, 1);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int n1, int n2) {
        int p1 = find(n1);
        int p2 = find(n2);

        if (p1 == p2) return false;

        if (rank[p2] > rank[p1]) 
            swap(p1, p2);
        
        rank[p1] += rank[p2];
        parent[p2] = p1;
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu = DSU(n);

        // email -> account idx
        unordered_map<string, int> mailAcc;
        
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                const string& email = accounts[i][j];
                if (mailAcc.count(accounts[i][j])) {
                    int p1 = mailAcc[email];
                    int p2 = i;
                    dsu.unite(p1, p2);
                } else 
                    mailAcc[email] = i;
            }
        }

        // root acct -> emails
        unordered_map<int, vector<string>> emailGroup;
        for (auto& [email, idx]: mailAcc) {
            int root = dsu.find(idx);
            emailGroup[root].push_back(email);
        }

        vector<vector<string>> res;
        for (auto& [idx, emails] : emailGroup) {
            vector<string> group;

            sort(emails.begin(), emails.end());
            const string name = accounts[idx][0];

            group.push_back(name);
            group.insert(group.end(), emails.begin(), emails.end());

            res.push_back(group);
        }
        return res;
    }
};
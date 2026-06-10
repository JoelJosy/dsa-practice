// Optimal Hierholzer's algo (Eulerian Path)
// T: O(ElogE)
// S: O(E+V) (recursion stack)

class Solution {
public:
    unordered_map<string, deque<string>> graph; // O(1) pop_front
    vector<string> res;
    
    void dfs(string node) {
        
        while (!graph[node].empty()) {
            string neigh = graph[node].front();
            graph[node].pop_front(); // remove edge
            dfs(neigh);
        }

        // exhausted all neighs, no more outgoing edges
        // must be the end node
        res.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());

        int n = tickets.size();
        for (auto& tick: tickets) {
            graph[tick[0]].push_back(tick[1]);
        }

        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};

// Build the path in reverse while backtracking.
// Keep following edges greedily until you get stuck. 
// When you're stuck, that node must be the end of that segment 
// add it to the result. Then unwind.



// DFS Backtracking (TLE)
// T: O(E.E!)
// S: O(E)
class Solution {
public:
    unordered_map<string, vector<string>> graph;
    
    bool dfs(int n, string node, vector<string>& curr) {
        if (curr.size() == n + 1) {
            return true;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            string neigh = graph[node][i];
            graph[node].erase(graph[node].begin() + i);

            curr.push_back(neigh);
            if (dfs(n, neigh, curr)) 
                return true;
            curr.pop_back();
            graph[node].insert(graph[node].begin() + i, neigh);
        }

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());

        int n = tickets.size();
        for (auto& tick: tickets) {
            graph[tick[0]].push_back(tick[1]);
        }

        vector<string> curr = {"JFK"};
        dfs(n, "JFK", curr);
        return curr;
    }
};


// sort edges, make adj list
// for each node do dfs, remove edges as we go
// add nodes to res
// if len(res) == len(tickets) + 1 => ans
// else backtrack and add back edges
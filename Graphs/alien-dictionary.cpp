// Time: O(C+V+E) C - total num of chars across all words N*L
// Space: O(V+E) graph and visited storage and recursion is O(V)

// DFS
class Solution {
public:
    // ["hrn","hrf","er","enn","rfnn"]
    // n -> f
    // h -> e
    // r -> n
    // e -> r
    // "hernf"
    bool dfs(char curr, string& res, unordered_map<char, unordered_set<char>>& graph, 
    unordered_set<char>& visited, unordered_set<char>& visiting) {
        // processed
        if (visited.count(curr)) return true; 
        // invalid if cycle
        if (visiting.count(curr)) return false; 

        visiting.insert(curr);
        for (char n: graph[curr]) {
            if (!dfs(n, res, graph, visited, visiting)) return false;
        }
        visiting.erase(curr);

        visited.insert(curr);
        res += curr;
        return true;
    }

    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> graph;
        for (string& word : words) {
            // O(C) C - no of chars
            // ensures char exists
            for (char c : word) graph[c]; 
        }

        // build graph
        for (int i = 0; i < n-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            
            if (w1.size() > w2.size() && w1.starts_with(w2)) 
            return "";
        
            int minlen = min(w1.size(), w2.size());
        
            // O(C) - no of words
            for (int j = 0; j < minlen; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }
        unordered_set<char> visited;
        unordered_set<char> visiting; // to check cycle (invalid)

        string res = "";
        
        // traverse all components in case disconnected
        // (multiple possibilities)
        for (auto& [c, _] : graph) {
            if (!dfs(c, res, graph, visited, visiting))
                return "";
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


// BFS
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;

        for (string& word : words) {
            // ensures char exists
            for (char c : word) {
                graph[c]; 
                indegree[c] = 0;
            }
        }

        // build graph
        for (int i = 0; i < n-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];

            if (w1.size() > w2.size() && w1.starts_with(w2)) 
                return "";
            
            int minlen = min(w1.size(), w2.size());

            for (int j = 0; j < minlen; j++) {
                if (w1[j] != w2[j]) {
                    if (!graph[w1[j]].count(w2[j])) {
                        graph[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        // insert initial into queue
        for (auto &p : graph) {
            if (indegree[p.first] == 0)
                q.push(p.first);
        }

        // BFS
        string res = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            res += curr;
            for (char nei : graph[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // if visited != no of unique chars
        // cycle exists
        if (res.size() != graph.size()) 
            return "";
        return res;
    }
};

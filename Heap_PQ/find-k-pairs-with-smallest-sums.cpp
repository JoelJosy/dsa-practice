// Optimal without visited
// T: O(klogk)
// S: O(k)
// similar to merge k sorted lists
// compare row wise, move across column

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        // {sum, i, j}
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < m; i++)
            pq.push({nums1[i]+nums2[0], i, 0});

        while (k--) {
            auto [sum, i, j] = pq.top(); pq.pop();
            res.push_back({nums1[i], nums2[j]});

            if (j+1 < n) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return res;
    }
};


// T: O(klogk)
// S: O(k)
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        // {sum, i, j}
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        // {i, j} -> store visited pairs
        set<pair<int, int>> visited;

        pq.push({nums1[0]+nums2[0], 0, 0});
        visited.insert({0, 0});

        while (k-- && !pq.empty()) {
            auto [sum, i, j] = pq.top(); pq.pop();

            res.push_back({nums1[i], nums2[j]});

            if (!visited.count({i+1, j}) && i+1 < nums1.size()) {
                pq.push({nums1[i+1] + nums2[j], i+1, j});
                visited.insert({i+1, j});
            }
            if (!visited.count({i, j+1}) && j+1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
                visited.insert({i, j+1});
            }
        }

        return res;
    }
};
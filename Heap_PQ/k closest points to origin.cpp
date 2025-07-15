// 973. K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution {
public:
    struct Compare {
        bool operator() (const vector<int>& a, const vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> heap;
        vector<vector<int>> res;
        for (const vector<int> point : points) {
            heap.push(point);
            if (heap.size() > k) {
                heap.pop();
            }
        }

        while (!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }

        return res;
    }
};


// Simpler
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> heap;
        vector<vector<int>> res;
        for (auto& point : points) {
            int x = point[0], y = point[1];
            heap.push({x*x + y*y, x, y});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        while (!heap.empty()) {
            vector<int> top = heap.top();
            res.push_back({top[1], top[2]});
            heap.pop();
        }

        return res;
    }
};
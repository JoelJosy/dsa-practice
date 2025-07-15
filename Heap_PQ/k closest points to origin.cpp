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
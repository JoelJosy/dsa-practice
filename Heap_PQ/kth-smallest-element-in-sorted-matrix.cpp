// Binary Search on value range using counts
// T: O(nlog(max-min))
// S: O(1)

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int lo = matrix[0][0];
        int hi = matrix[n-1][n-1];

        while (lo <= hi) {
            int mid = lo + (hi-lo) / 2;
            if (getcount(matrix, mid) < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }

    // O(n)
    int getcount(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int i = n - 1;
        int j = 0;
        int count = 0;

        while (i >= 0 && j < n) {
            if (matrix[i][j] <= mid) {
                count += (i + 1);
                j++;
            } else
                i--;
        }
        return count;
    }
};

// [ 1, 5, 9]
// [10,11,13]
// [12,13,15]


// Heap
// T: O(klog m)
// S: O(m)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<
            tuple<int, int, int>, 
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++)
            pq.push({matrix[i][0], i, 0});

        while (k > 1) {
            auto [num, i, j] = pq.top(); pq.pop();

            if (j+1 < n) {
                pq.push({matrix[i][j+1], i, j+1});
            }
            k--;
        }

        auto [num, i, j] = pq.top();
        return num;
    }
};

// [ 1, 5, 9]
// [10,11,13]
// [12,13,15]
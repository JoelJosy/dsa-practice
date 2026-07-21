// T: O(n)
// S: O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n+1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        int res = INT_MAX;
        deque<int> dq;
        for (int j = 0; j <= n; j++) {
            // pop valid and track min len
            while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                res = min(res, j - dq.front());
                dq.pop_front();
            }
            
            // pop to maintain increasing order
            // least prefix in front
            while (!dq.empty() && prefix[dq.back()] >= prefix[j]) {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return (res == INT_MAX) ? -1 : res;
    }
};

// value:    5   -4   -2   10
// index:    0    1    2    3    4
// prefix:   0    5    1   -1    9
// prefix[j] - prefix[i] >= k
// and for curr j, find most recent i (for shortest subarray) 
// greater diff => lesser prefix[i]
// recent i => larger i
// monotonic increasing queue of idxs satisfying prefix condition
// can also use minheap
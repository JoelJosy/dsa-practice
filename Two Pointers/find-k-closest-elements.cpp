// Insertion + Two pointer expansion
// Use deque to maintain order
// T: O(logn + k)
// S: O(k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;

        deque<int> dq;

        while (k--) {
            if (l < 0) {
                dq.push_back(arr[r++]);
            }
            else if (r >= arr.size()) {
                dq.push_front(arr[l--]);
            }
            else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                dq.push_front(arr[l--]);
            }
            else {
                dq.push_back(arr[r++]);
            }
        }

        return vector<int>(dq.begin(), dq.end());
    }
};


// Insertion + Two pointer expansion
// T: O(logn + klogk)
// S: O(k)
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r - 1;

        vector<int> res;
        while (k--) {
            if (l < 0) {
                res.push_back(arr[r++]);
            }
            else if (r >= arr.size()) {
                res.push_back(arr[l--]);
            }
            else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                res.push_back(arr[l--]);
            }
            else {
                res.push_back(arr[r++]);
            }
        }
        return res;
    }
};















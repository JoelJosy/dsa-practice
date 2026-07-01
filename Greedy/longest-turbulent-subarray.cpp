// T: O(n)
// S: O(1)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.empty()) return 0;

        int res = 1;
        int len = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (i >= 2 && (
                (arr[i-2] > arr[i-1] && arr[i-1] < arr[i]) || 
                (arr[i-2] < arr[i-1] && arr[i-1] > arr[i]))
            ) {
                len++;
            } else if (arr[i] != arr[i-1]) {
                len = 2;
            } else 
                len = 1;
            res = max(res, len);
        }
        return res;
    }
};

// if peak or valley, extend run
// if not, if curr and prev diff, they are turbulent
// reset to 2 (length of turbulent starts from prev two)
// if curr and prev same, reset to 1
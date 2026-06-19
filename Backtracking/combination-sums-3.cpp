// T: O(2^9)
// S: O(k)

class Solution {
public:
    vector<vector<int>> res;
    void backtrack(int k, int target, int num, vector<int>& curr) {
        if (k == curr.size() && target == 0) {
            res.push_back(curr);
            return;
        }

        if (curr.size() > k) return;

        for (int i = num; i < 10; i++) {
            if (target - i < 0)     
                break;
            
            curr.push_back(i);
            backtrack(k, target - i, i+1, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        backtrack(k, n, 1, curr);
        return res;
    }
};
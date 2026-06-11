// T: O(n + kh) or O(n^2) worst case (skewed tree, all valid)
// S: O(kh) 
// n nodes, k valid paths, h height
class Solution {
public:
    vector<vector<int>> res;
    void dfs(TreeNode* node, int target, vector<int>& curr) {
        if (!node) return;

        target -= node->val;
        curr.push_back(node->val);

        if (target == 0 && !node->left && !node->right) {
            // O(h)
            res.push_back(curr);
        } else {
            if (node->left) dfs(node->left, target, curr);
            if (node->right) dfs(node->right, target, curr);
        }

        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> curr;
        dfs(root, targetSum, curr);
        return res;
    }
};
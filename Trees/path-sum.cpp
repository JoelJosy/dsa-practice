// T: O(n)
// S: O(h)
class Solution {
public:
    bool dfs(TreeNode* node, int target) {
        if (!node) return false;

        target -= node->val;

        if (!node->left && !node->right) {
            return target == 0;
        }

        return dfs(node->left, target) || dfs(node->right, target);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }
};
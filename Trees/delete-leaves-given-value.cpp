// T: O(n)
// S: O(n)
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;

        if (root->left) {
            root->left = removeLeafNodes(root->left, target);
        } 
        if (root->right) {
            root->right = removeLeafNodes(root->right, target);
        }

        if (!root->left && !root->right && root->val == target) {
            return nullptr;
        }

        return root;
    }
};

// process children first, then parents -> postorder dfs
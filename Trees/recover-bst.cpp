// T: O(n)
// S: O(1)
class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val > root->val) {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};

// Inorder traversal,
// 1 2 3 4 5 6 7
// 1 6 3 4 5 2 7
// 2 pass, check if prev > curr
// 5 and 6 swapped
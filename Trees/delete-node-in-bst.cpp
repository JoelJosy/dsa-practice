// T: O(h) n worst case for both
// S: O(h)
class Solution {
public:
    TreeNode* getSucc(TreeNode* node) {
        if (node->left) 
            return getSucc(node->left);
        else 
            return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) 
            root->left = deleteNode(root->left, key);
        else if (key > root->val) 
            root->right = deleteNode(root->right, key);
        else {
            // one child
            if (!root->right) return root->left;
            if (!root->left) return root->right;

            // both children
            TreeNode* succ = getSucc(root->right);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};

// for deletion
// subst with inorder successor or predecessor
// ie, smallest in right or largest in left subtree
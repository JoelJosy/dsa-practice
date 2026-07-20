// T: O(n)
// T: O(n)
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool foundNull = false;
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (!node) {
                foundNull = true;
                continue;
            }

            if (foundNull) return false;

            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};
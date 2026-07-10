// T: O(n)
// S: O(h)
class Solution {
public:
    int dfs(TreeNode* root, int num) {
        if (!root) return 0;
        
        num = num * 10 + root->val;
        if (!root->left && !root->right) return num;

        int left = dfs(root->left, num);
        int right = dfs(root->right, num);

        return left + right;
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
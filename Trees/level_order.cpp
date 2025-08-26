// 102. Binary Tree Level Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* popped = q.front();
                q.pop();
                level.push_back(popped->val);

                if (popped->left) q.push(popped->left);
                if (popped->right) q.push(popped->right);
            }

            res.push_back(level);
        }

        return res;
    }
};
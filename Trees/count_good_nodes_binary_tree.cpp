// 1448. Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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

    void dfs(TreeNode* root, int* count, int maxVal) {
        if (!root) return;

        if (root->val >= maxVal) {
            (*count)++;
        }
        maxVal = max(maxVal, root->val);

        dfs(root->left, count, maxVal);
        dfs(root->right, count, maxVal);
    }

    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int count = 0;
        int maxVal = root->val;

        dfs(root, &count, maxVal);

        return count;
    }
};

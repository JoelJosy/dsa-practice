// 543 Diameter of a binary tree
// https://leetcode.com/problems/diameter-of-binary-tree/submissions/1715421795/

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
    int height(TreeNode* root, int& diam) {
        if (!root) return 0;
        int left = height(root->left, diam);
        int right = height(root->right, diam);
        diam = max(diam, left+right);
        return 1 + max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        height(root, diam);
        return diam;
    }
};
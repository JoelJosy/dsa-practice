#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {} 
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {} 
};

TreeNode* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return nullptr;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    int i = 1;
    while (i < arr.size() && !q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        if (i<arr.size() && arr[i] != -1) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

void printTree(TreeNode* root) {
    if (!root) cout << "Empty Tree";

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " "

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    if (root == p || root == q) return root;

    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);

    if (left && right) return root;

    return (left) ? left : right;
}
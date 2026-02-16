#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

TreeNode* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return nullptr;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();    

        // Left child
        if (i < arr.size() && arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }

    return root;
}

TreeNode* invert(TreeNode* root) {
    if (!root) return nullptr;

    swap(root->left, root->right);

    invert(root->left);
    invert(root->right);
    return root;
}

void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    TreeNode* root = buildTree(arr);
    TreeNode* inverted = invert(root);
    printTree(inverted);

    return 0;
}
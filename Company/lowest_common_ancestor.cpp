
TreeNode* buildTree(vector<int>& arr) {
    if (arr.size() == 0 || arr[0] == -1) return nullptr;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);

    i=1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1) {
            node->left = arr[i];
            q.push(node->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1) {
            node->right = arr[i];
            q.push(node->right);
        }
        i++;
    }
    return root;
}
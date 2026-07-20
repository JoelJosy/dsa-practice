// T: O(n)
// S: O(n)
class Solution {
public:
    unordered_map<int, int> mp;
    int idx;

    TreeNode* construct(vector<int>& postorder, int l, int r) {
        if (l > r) return nullptr;

        int root = postorder[idx--];
        TreeNode* node = new TreeNode(root);

        int mid = mp[root];

        node->right = construct(postorder, mid + 1, r);
        node->left = construct(postorder, l, mid - 1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        idx = n - 1;

        for (int i = 0; i < n; i++) 
            mp[inorder[i]] = i;

        return construct(postorder, 0, n - 1);
    }
};
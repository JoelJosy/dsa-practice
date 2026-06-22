// Optimal
// Tree DP
// T: O(n)
// S: O(h) 
class Solution {
public:
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int rob = root->val + left.second + right.second;
        int skip = max(left.first, left.second) +
                   max(right.first, right.second);
        return {rob, skip};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};

// state: {rob, skip}
// for each node, find max in subtrees if:
// a) rob root
// b) skip root

// DFS + memo
// T: O(n)
// S: O(n) worst case skewed tree
class Solution {
public:
    unordered_map<TreeNode*, int> dp0; // parent not robbed
    unordered_map<TreeNode*, int> dp1; // parent robbed

    int dfs(TreeNode* node, bool parentRobbed) {
        if (!node) return 0;

        if (parentRobbed) {
            if (dp1.count(node)) return dp1[node];

            int res =
                dfs(node->left, false) +
                dfs(node->right, false);

            return dp1[node] = res;
        }

        if (dp0.count(node)) return dp0[node];

        int skip =
            dfs(node->left, false) +
            dfs(node->right, false);

        int rob =
            node->val +
            dfs(node->left, true) +
            dfs(node->right, true);

        return dp0[node] = max(rob, skip);
    }

    int rob(TreeNode* root) {
        return dfs(root, false);
    }
};

// DFS
// T: O(2^n)
// S: O(n) worst case skewed tree
class Solution {
public:
    int dfs(TreeNode* root, bool parentRobbed) {
        if (!root) return 0;

        if (parentRobbed) {
            return dfs(root->left, false) + dfs(root->right, false);
        }

        int skip = dfs(root->left, false) + dfs(root->right, false);
        int rob = root->val;
        rob += dfs(root->left, true) + dfs(root->right, true);
        return max(rob, skip);
    }

    int rob(TreeNode* root) {
        return max(dfs(root, false), dfs(root, true));
    }
};
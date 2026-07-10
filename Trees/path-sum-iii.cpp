// T: O(n)
// S: O(h) or O(n) worst case
class Solution {
public:
    // path sum -> freq
    unordered_map<long long, int> mp;
    int res = 0;

    void dfs(TreeNode* node, int target, long long currsum) {
        if (!node) return;

        currsum += node->val;
        res += mp[currsum-target];
        
        mp[currsum]++;

        dfs(node->left, target, currsum);
        dfs(node->right, target, currsum);

        mp[currsum]--;

    }

    int pathSum(TreeNode* root, int targetSum) {
        // for case where root == target
        mp[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }
};

// how many times have we seen sum equal to currpathsum - target 

// T: O(n^2)
// S: O(h) or O(n) worst case
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
    // count paths that must start at root
    int dfs(TreeNode* root, int target) {
        if (!root) return 0;

        int count = 0;

        if (root->val == target) count++;

        count += dfs(root->left, target - root->val);
        count += dfs(root->right, target - root->val);
        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return dfs(root, targetSum) +
                pathSum(root->left, targetSum) +
                pathSum(root->right, targetSum);
    }
};
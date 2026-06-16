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
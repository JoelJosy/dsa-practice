// T: O(n)
// S: O(n)

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        bool dirn = true;
        while (!q.empty()) {
            int size = q.size();
            deque<int> leveldq;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (dirn)
                    leveldq.push_back(node->val);
                else
                    leveldq.push_front(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            vector<int> level(leveldq.begin(), leveldq.end());
            res.push_back(level);
            dirn = !dirn;
        }
        return res;
    }
};
// 297. Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        queue<TreeNode*> q;
        q.push(root);
        string res = "";

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            if (front) {
                res += to_string(front->val) + ",";
                q.push(front->left);
                q.push(front->right);
            } else {
                res += "null,";
            }
        }
        if (!res.empty()) res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;

        stringstream ss(data);
        string token;
        vector<string> values;

        while (getline(ss, token, ',')) {
            values.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(values[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < values.size()) {
            TreeNode* front = q.front();
            q.pop();

            string leftVal = values[i++];
            if (leftVal != "null") {
                front->left = new TreeNode(stoi(leftVal));
                q.push(front->left);
            }
            if (i >= values.size()) break;

            string rightVal = values[i++];
            if (rightVal != "null") {
                front->right = new TreeNode(stoi(rightVal));
                q.push(front->right);
            } 
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
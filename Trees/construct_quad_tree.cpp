// T: O(n^2 * logn)
// S: O(logn)
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool isLeaf(vector<vector<int>>& grid, int n, int row, int col) {
        int ele = grid[row][col];

        for (int i = row; i < row + n; i++) {
            for (int j = col; j < col + n; j++) {
                if (grid[i][j] != ele)
                    return false;
            }
        }

        return true;
    }

    Node* buildTree(vector<vector<int>>& grid, int n, int row, int col) {
        if (isLeaf(grid, n, row, col)) {
            bool val = (grid[row][col] == 1) ? true : false;
            return new Node(val, true);
        }

        // divide by 4 
        Node* node = new Node(false, false);
        node->topLeft = buildTree(grid, n/2, row, col);
        node->topRight = buildTree(grid, n/2, row, col + n/2);
        node->bottomLeft = buildTree(grid, n/2, row + n/2, col);
        node->bottomRight = buildTree(grid, n/2, row + n/2, col + n/2);
        return node;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return buildTree(grid, grid.size(), 0, 0);
    }
};


// Optimal
// T: O(n^2)
// S: O(logn)

class Solution {
public:
    Node* buildTree(vector<vector<int>>& grid, int n, int row, int col) {
        if (n == 1) 
            return new Node(grid[row][col] == 1, true);

        // divide by 4 
        Node* topLeft = buildTree(grid, n/2, row, col);
        Node* topRight = buildTree(grid, n/2, row, col + n/2);
        Node* bottomLeft = buildTree(grid, n/2, row + n/2, col);
        Node* bottomRight = buildTree(grid, n/2, row + n/2, col + n/2);

        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && bottomLeft->val == bottomRight->val && topLeft->val == bottomRight->val)
            return new Node(topLeft->val, true);

        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return buildTree(grid, grid.size(), 0, 0);
    }
};
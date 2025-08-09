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
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }
    
private:
    Node* build(vector<vector<int>>& grid, int row, int col, int length) {

        if (isUniform(grid, row, col, length)) {

            return new Node(grid[row][col] == 1, true);
        }
        

        int half = length / 2;
        
        Node* topLeft     = build(grid, row, col, half);
        Node* topRight    = build(grid, row, col + half, half);
        Node* bottomLeft  = build(grid, row + half, col, half);
        Node* bottomRight = build(grid, row + half, col + half, half);
        

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    bool isUniform(vector<vector<int>>& grid, int row, int col, int length) {
        int firstVal = grid[row][col];
        for (int i = row; i < row + length; i++) {
            for (int j = col; j < col + length; j++) {
                if (grid[i][j] != firstVal) {
                    return false;
                }
            }
        }
        return true;
    }
};

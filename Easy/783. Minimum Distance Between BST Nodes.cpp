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
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }
    void inorder(TreeNode* node, int& prev, int& minDiff){
        if(!node){
            return;
        }
        inorder(node->left, prev, minDiff);

        if(prev != -1){
            minDiff = min(minDiff, node->val - prev);
        }
        prev = node->val;

        inorder(node->right, prev, minDiff);
    }
};

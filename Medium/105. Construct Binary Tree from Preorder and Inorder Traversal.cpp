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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0;
        return helper(preorder, inorder, preStart, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preStart, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        preStart++;  // This now updates the reference correctly

        int rootIndex = inStart;
        while (rootIndex <= inEnd && inorder[rootIndex] != rootVal) {
            rootIndex++;
        }

        root->left = helper(preorder, inorder, preStart, inStart, rootIndex - 1);
        root->right = helper(preorder, inorder, preStart, rootIndex + 1, inEnd);
        return root;
    }
};

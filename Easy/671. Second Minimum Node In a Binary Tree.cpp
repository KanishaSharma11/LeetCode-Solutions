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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root){
            return -1;
        }

        int ans = - 1;
        int rootVal = root->val;
        dfs(root, rootVal, ans);
        return ans;
    }

    void dfs(TreeNode* node, int rootVal, int& ans){
        if(!node){
            return;
        }
        if(node->val > rootVal){
            if(ans == -1 || node->val < ans){
                ans = node->val;
            }
        }
        else if(node->val == rootVal){
            dfs(node->left, rootVal, ans);
            dfs(node->right, rootVal, ans);
        }
    }
};

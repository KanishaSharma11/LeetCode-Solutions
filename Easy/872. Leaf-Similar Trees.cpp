class Solution {
public:
    void getLeaves(TreeNode* root, vector<int>& leaf){
        if(!root){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            leaf.push_back(root->val);
        }
        getLeaves(root->left, leaf);
        getLeaves(root->right, leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;
        getLeaves(root1, leaf1);
        getLeaves(root2, leaf2);
        return leaf1 == leaf2;
    }
};

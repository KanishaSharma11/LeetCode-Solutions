class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* tempRight = root->right;

        root->right = root->left;
        root->left = NULL;

        TreeNode* current = root;
        while(current->right){
            current = current->right;
        }

        current->right = tempRight;
    }
};

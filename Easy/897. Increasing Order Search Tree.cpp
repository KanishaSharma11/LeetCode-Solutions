class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>& arr){
        if(!root){
            return;
        }

        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> arr;
        inorder(root, arr);

        TreeNode* newRoot = new TreeNode(arr[0]->val);
        TreeNode* temp = newRoot;
        for(int i = 1; i < arr.size(); i++){
            temp->right = new TreeNode(arr[i]->val);
            temp = temp->right;
            temp->left = NULL;
        }

        return newRoot;
    }
};

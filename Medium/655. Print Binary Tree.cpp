class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root) - 1;
        int m = height + 1;
        int n = (1 << (height + 1)) - 1;

        vector<vector<string>> res(m, vector<string>(n, ""));

        fillMatrix(res, root, 0, (n - 1) / 2, height);

        return res;
    }

    int getHeight(TreeNode* root){
        if(!root) return 0;

        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fillMatrix(vector<vector<string>>& res, TreeNode* node, int row, int pos, int height){
        if(!node) return;
        res[row][pos] = to_string(node->val);
        
        if(row < height){
            int offset = 1 << (height - row - 1);
            fillMatrix(res, node->left, row+1, pos-offset, height);
            fillMatrix(res, node->right, row + 1, pos + offset, height);
        }
    }
};

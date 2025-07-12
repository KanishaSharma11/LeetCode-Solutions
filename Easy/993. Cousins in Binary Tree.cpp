class Solution {
public:
    void findNodeInfo(TreeNode* node, int x, TreeNode* parent, int depth, int& foundDepth, TreeNode*& foundParent){
        if(!node) return ;
        if(node->val == x){
            foundDepth = depth;
            foundParent = parent;
            return;
        }
        findNodeInfo(node->left, x, node, depth+1, foundDepth, foundParent);
        findNodeInfo(node->right, x, node, depth+1, foundDepth, foundParent);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int depthX = - 1, depthY = -1;
        TreeNode* parentX = NULL;
        TreeNode* parentY = NULL;

        findNodeInfo(root, x, NULL, 0, depthX, parentX);
        findNodeInfo(root, y, NULL, 0, depthY, parentY);

        return (depthX == depthY) && (parentX != parentY);
    }
};

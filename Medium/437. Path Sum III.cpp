class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        int count = countPaths(root, targetSum);

        count+=pathSum(root->left, targetSum);
        count+=pathSum(root->right, targetSum);

        return count;
    }
    int countPaths(TreeNode* node, long long targetSum){
        if(!node) return 0;
        int count = (node->val == targetSum) ? 1: 0;
        count+=countPaths(node->left, targetSum - node->val);
        count+=countPaths(node->right, targetSum - node->val);
        return count;
    }
};

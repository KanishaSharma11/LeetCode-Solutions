class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root){
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            int prevVal = level % 2 == 0 ? INT_MIN : INT_MAX;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                int val = node->val;

                if(level % 2 == 0){
                    if(val % 2 == 0 || val <= prevVal){
                        return false;
                    }
                }
                else{
                    if(val % 2 != 0 || val >= prevVal){
                        return false;
                    }
                }
                prevVal = val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            level++;

        }
        return true;
    }
};

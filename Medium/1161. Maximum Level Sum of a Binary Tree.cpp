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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        long long MAXSUM = LLONG_MIN;
        int answerLevel = 1;
        int level = 1;

        while(!q.empty()){
            int size = q.size();
            long long currentSum = 0;

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();

                currentSum += temp->val;

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            if(currentSum > MAXSUM){
                MAXSUM = currentSum;
                answerLevel = level;
            }
            level++;
        }
        return answerLevel;
    }
};

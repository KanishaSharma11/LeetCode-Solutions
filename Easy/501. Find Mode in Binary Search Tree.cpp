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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        
        if(ans.empty()){
            return {};
        }

        int maxCount = 1;
        int currentCount = 1;
        vector<int> result;

        for(int i = 1; i < ans.size(); i++){
            if(ans[i] == ans[i - 1]){
                currentCount++;
            }
            else{
                if(currentCount > maxCount){
                    maxCount = currentCount;
                    result.clear();
                    result.push_back(ans[i - 1]);
                }
                else if(currentCount == maxCount){
                    result.push_back(ans[i - 1]);
                }
                currentCount = 1;
            }
        }

        if(currentCount > maxCount){
            result.clear();
            result.push_back(ans.back());
        }
        else if(currentCount == maxCount){
            result.push_back(ans.back());
        }

        return result;
    }
};

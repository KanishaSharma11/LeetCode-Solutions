class Solution {
public:
    void preOrderTraversal(Node* root, vector<int>& result){
        if(root == NULL){
            return ;
        }
        result.push_back(root->val);
        for(auto& child: root->children){
            preOrderTraversal(child, result);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> result;
        preOrderTraversal(root, result);
        return result;
    }
};

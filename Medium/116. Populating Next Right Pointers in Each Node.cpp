class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        Node* current = root;
        while(current->left){
            Node* temp = current;
            while(temp){
                temp->left->next = temp->right;
                if(temp->next){
                    temp->right->next = temp->next->left;
                }
                temp = temp->next;
            }
            current = current->left;
        }
        return root;
    }
};

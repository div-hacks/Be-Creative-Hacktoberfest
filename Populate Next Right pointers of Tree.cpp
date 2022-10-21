class Solution {
public:
 
    
    Node* connect(Node* root) {
        Node* temp = root;
        while(temp != NULL){
            Node* start = temp;
            temp = start->left;
            if(temp!=NULL){
                while(start != NULL){
                    start->left->next = start->right;
                    if(start->next != NULL){
                        start->right->next = start->next->left;
                    }
                    start = start->next;
                }
            }
        }
        return root;
    }
};

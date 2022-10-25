#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

void BFS(struct node* root){
    queue<struct node*> q;
    vector<int> ans;
    q.push(root);
    while(!q.empty()){
        struct node* temp = q.front();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
        ans.push_back(temp->data);
        q.pop();
    }

    for(auto i:ans)
        cout<<i<<" ";
}

vector<int> MorrisTraversal(struct node* root){
    vector<int> inorder;
    struct node* cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            inorder.push_back(cur->data);
            cur = cur->right;
        } else {
            struct node* prev = cur->left;
            while(prev->right && prev->right != cur)
                prev = prev->right;

            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur = cur->right;
            }

        }
    }

    return inorder;
}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(6);
    vector<int> inorder = MorrisTraversal(root);
    for(int i:inorder)
        cout<<i<<" ";
    /*
              1
             / \
            2   3
           / \
          4   5
               \
                6
    */
    return 0;
}

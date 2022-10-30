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

int Diameter(struct node* root, int& D){
    if(root == NULL)
        return 0;

    int lh = Diameter(root->left,D);
    int rh = Diameter(root->right,D);

    D = max(lh+rh, D);
    // int diameter = lh + rh;

    // if(diameter > D)
    //     D = diameter;

    return max(lh,rh)+1;

}

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->left->left = new node(5);
    root->right->left->left->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(8);
    root->right->right->right->right = new node(9);

    // root->left->left = new node(4);
    // root->left->right = new node(5);
    /*
              1
             / \
            2   3
           / \ / \
          4   5x   x
         / \
        x   x
    */
    int D = 0;
    int height = Diameter(root, D);
    cout<<D;
    return 0;
}

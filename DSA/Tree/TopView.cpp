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

void Topview(struct node* root){
    map<int,int> mp;
    queue<pair<struct node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        int x = temp.second;
        struct node* node1 = temp.first;
        if(mp.find(x) == mp.end())
            mp[x] = node1->data;
        if(node1->left)
            q.push({node1->left, x-1});
        if(node1->right)
            q.push({node1->right, x+1});
    }
    vector<int> v;
    for (const auto &s : mp)
        v.push_back(s.second);
    for(auto i: v)
        cout<<i<<" ";
}
int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right->right = new node(7);
    Topview(root);
    /*
              1
             / \
            2   3
           / \   \
          4   5   7
             /
            6
    */
    return 0;
}

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

void MaxWidth(struct node* root){
    queue<pair<struct node*, int>> q;
    q.push({root,0});
    int ans = INT_MIN;
    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;
        int first,last;
        for(int i=0; i<size; i++){
            int curr_id = q.front().second - mmin;
            struct node* temp = q.front().first;
            q.pop();
            if(i==0) first = curr_id;
            if(i==size-1) last = curr_id;

            if(temp->left)
                q.push({temp->left, curr_id*2 + 1});
            if(temp->right)
                q.push({temp->right, curr_id*2 + 2});
        }
        ans = max(ans, last-first+1);
    }
    cout<<ans;
}
int main(){
    struct node* root = new node(1);
    root->left = new node(3);
    root->right = new node(7);
    root->right->right = new node(4);
    root->left->left = new node(8);
    MaxWidth(root);
    /*
              1
             / \
            3   7
           /     \
          8       4
    */
    return 0;
}

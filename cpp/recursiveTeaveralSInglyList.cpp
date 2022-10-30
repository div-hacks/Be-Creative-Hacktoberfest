#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int n){
        data=n;
        next=NULL;
    }
};
Node *takeInput(){
    int n;
    cin>>n;
    Node *head=NULL;
    Node *tail=NULL;
    while(n!=-1){
        Node *temp=new Node(n);
        if(head==NULL){
            tail=temp;
            head=tail;
        }
        else{
            tail->next=temp;
            tail=tail->next;
        }
        cin>>n;
    }
    return head;
}

void print(Node *head){
    if(head==NULL) return;
    cout<<head->data<<" ";
    print(head->next);
}
int main(int argc, char const *argv[])
{
    int n;
    Node *head=takeInput();
    print(head);
    return 0;
}

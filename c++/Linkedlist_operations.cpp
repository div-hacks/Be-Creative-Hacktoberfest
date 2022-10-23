#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};
void printlist(Node *head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}
void search(Node* head,int x){
    int pos=1,ans=-1;
    Node* curr=head;
    while(curr!=NULL){
        if(curr->data==x){
            ans=pos;
            break;
        }
        else{
            pos++;
            curr=curr->next;
        }
    }
    cout<<ans;
}
Node* insertatbegin(Node* head,int x){
    Node* temp=new Node(x);
    temp->next=head;
    return temp;
}
void insertatend(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL){
        head=temp;
    }
    Node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}
Node* delfrombeg(Node* head){
    if(head==NULL){
        return NULL;
    }
    else{
        Node* temp=head->next;
        delete(head);
        return temp;
    }
}
Node* dellast(Node* head){
    if(head==NULL) return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node* curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete(curr->next);
    curr->next=NULL;
    return head;
}
Node* insertatpos(Node* head,int pos,int x){
    Node* temp=new Node(x);
    if(pos==1){
        temp->next=head;
        return temp;
    }
    Node* curr=head;
    for(int i=1;i<pos-2 && curr!=NULL;i++){
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return curr;
}
Node* sorted(Node* head,int x){
    Node* temp=new Node(x);
    if(head==NULL){
        return temp;
    }
    if(x<head->data){
        temp->next=head;
        return temp;
    }
    Node* curr=head;
    while(curr->next!=NULL && curr->next->data<x){
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
void printmiddle(Node* head){
    if(head==NULL) return;
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}
void printnthend(Node* head,int n){
    Node* fast=head,*slow=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    cout<<slow->data;
}
Node* reverselist(Node* head){
    if(head==NULL) return head;
    Node* prev=NULL,*curr=head;
    while(curr!=NULL){
        Node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void removedup(Node* head){
    Node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            delete temp;
        }
        else{
            curr=curr->next;
        }
    }
}
int main(){
    Node *temp1=new Node(10);
    Node *temp2=new Node(20);
    Node *temp3=new Node(20);
    Node *temp4=new Node(40);
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=temp4;
    insertatend(temp1,50);
    printlist(temp1);
    Node* nhead=sorted(temp1,40);
    printnthend(temp1,2);
    removedup(temp1);
    printlist(temp1);
    printmiddle(temp1);
   Node* nnode=reverselist(temp1);
    printlist(nnode);
   search(temp1,20);
}

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtTail(Node* &tail, int val){
    Node* temp = new Node(val);
    tail->next = temp;
    tail = temp;
}

void deleteNode(Node* head, int pos) {
    Node* temp = head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main()
{
    Node* node = new Node(1);
    Node* tail = node;
    Node* head = node;
    
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    
    print(head);

    
    deleteNode(head,3);
    
    print(head);

    return 0;
}

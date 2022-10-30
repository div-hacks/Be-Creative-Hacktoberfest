#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};
Node *inputNode(){
    Node *head=NULL;
    Node *temp=NULL;
    int data;
    cin>>data;
    while(data!=-1){
        Node *n=new Node(data);
        if(head==NULL){
            head=n;
            temp=n;
        }else{
            temp->next=n;
            temp=temp->next;
        }
        cin>>data;
    }
    return head;
}
void print_ith_node(Node *head, int i){
    int count=0;
    while(head!=NULL){
        if(count==i) {cout<<i<<"th Node is :"<<head->val<<endl;break;}
        head=head->next;
        count++;
    }
}
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        Node *head=inputNode();
        int i;
        cin>>i;
        print_ith_node(head,i);
    }
    return 0;
}

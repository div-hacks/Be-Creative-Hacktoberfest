#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:

    int size;
    int front;
    int rear;
    int* arr;
};
int isempty(Queue *q){
    if(q->rear==q->front){
        return 1;
    }
    return 0;
}
int isfull(Queue *q){
    if(q->rear==q->size-1){
        return 1;
    }
    return 0;
}
void enqueue(Queue *q,int val){
    if(isfull(q)){
        cout<<"Queue is full\n";
    }
    else{
        q->rear++;
        q->arr[q->rear]=val;
    }
}
int dequeue(Queue *q){
    int a=-1;
    if(isempty(q)){
        cout<<"This queue is empty\n";
    }
    else{
        q->front++;
        a=q->arr[q->front];
    }
    return a;
}

int main()
{
    // initializing queue(array implementation)
    Queue q;
    q.size=400;
    q.front=q.rear=0;
    q.arr=(int*)malloc(q.size*sizeof(int));

    // BFS implementation
    int node;
    int i=1;
    int visted[7]={0,0,0,0,0,0,0};
/*

Given graph


    0-------1
    | \     |
    |   \   |
    |     \ |
    2-------3
     \     /
      \   /
       \ /
        4
       / \
      /   \
     5     6

*/
    int visited[7]={0,0,0,0,0,0,0};
    int a[7][7]={
        {0,1,1,1,0,0,0},             
        {1,0,0,1,0,0,0},            
        {1,0,0,1,1,0,0},           
        {1,1,1,0,0,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    cout<<i;
    visited[i]=1;
    enqueue(&q,i);// enqueue i for exploration
    while(!isempty(&q))
    {
        int node=dequeue(&q);
        for(int j=0;j<7;j++){
            if(a[node][j]==1 && visited[j]==0){
                cout<<j;
                visited[j]=1;
                enqueue(&q,j);
            }
        }
    }
return 0;
}
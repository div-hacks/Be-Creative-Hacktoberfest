
#include<bits/stdc++.h>

using namespace std;


struct minHeap{
    int size;
    int capacity;
    int *arr=new int[capacity];

    minHeap(int c){
        arr=new int[c];
        capacity=c;
        size=0;
    }
};

int leftchild(int i){
    return 2*i+1;
}
int rightchild(int i){
    return 2*i+2;
}
int parent(int i){
    return (i-1)/2;
}


void insert(minHeap *m,int key){
    if(m->size==m->capacity)
        cout<<"Heap is Full"<<endl;
    else if(m->size==0){
        m->size++;
        m->arr[m->size-1]=key;
    }
    else{
        m->size++;
        m->arr[m->size-1]=key;
        int i=m->size-1;
        while(i!=0 && m->arr[i]<m->arr[parent(i)]){
            swap(m->arr[i],m->arr[parent(i)]);
            i=parent(i);
        }
    }
}

void printHeap(minHeap *m){
    for(int i=0;i<m->size;i++){
        cout<<m->arr[i]<<" ";
    }
}

int main(){
      minHeap mh(10);

      insert(&mh,10);
      insert(&mh,20);
      insert(&mh,15);
      insert(&mh,40);
      insert(&mh,50);
      insert(&mh,100);
      insert(&mh,25);
      insert(&mh,45);
      insert(&mh,12);

      printHeap(&mh);

      return 0;
}

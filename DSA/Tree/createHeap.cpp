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
    int leftchild(int i){
        return 2*i+1;
    }
    int rightchild(int i){
        return 2*i+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
};


int main(){
      minHeap mh(5);
      return 0;
}

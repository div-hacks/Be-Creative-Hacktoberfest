
#include<bits/stdc++.h>

using namespace std;


int leftchild(int i){
    return 2*i+1;
}
int rightchild(int i){
    return 2*i+2;
}
int parent(int i){
    return (i-1)/2;
}



void minHeapify(int arr[],int size,int i){
   int lc=leftchild(i);
   int rc=rightchild(i);
   int smallest=i;
   if(lc<size && arr[lc]<arr[smallest])
        smallest=lc;
   if(rc<size && arr[rc]<arr[smallest])
        smallest=rc;
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        minHeapify(arr,size,smallest);
    }
}


int extractMin(int arr[],int size){
    if(size==1){
        size--;
        return arr[size];
    }
    swap(arr[0],arr[size-1]);
    size--;
    minHeapify(arr,size,0);
    return arr[size];
}


int main(){
      int arr[]={20,25,30,35,40,80,32,100,70,60};
      int size=10;
      cout<<extractMin(arr,size);
      return 0;
}

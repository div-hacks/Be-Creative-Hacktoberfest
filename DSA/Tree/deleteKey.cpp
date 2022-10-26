
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

void extractMin(int arr[],int &size){
    if(size==1){
        size--;
    }
    swap(arr[0],arr[size-1]);
    size--;
    minHeapify(arr,size,0);
}
void decreaseKey(int arr[],int size,int i,int x){
    if(i>size)
        return;
    arr[i]=x;
    while(i!=0 && arr[parent(i)]>arr[i]){
        swap(arr[parent(i)],arr[i]);
        i=parent(i);
    }
}

void deleteKey(int arr[],int &size,int i){
    decreaseKey(arr,size,i,INT_MIN);
    extractMin(arr,size);
}

void printHeap(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
      int arr[]={10,20,30,40,50,35,38,45};
      int size=8;
      int i=3;
      int x=10;
      deleteKey(arr,size,i);
      printHeap(arr,size);
      return 0;
}


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

int main(){
      int arr[]={40,20,30,35,25,80,32,100,70,60};
      int size=10;

      minHeapify(arr,size,0);

      for(int i=0;i<size;i++)
        cout<<arr[i]<<endl;

      return 0;
}

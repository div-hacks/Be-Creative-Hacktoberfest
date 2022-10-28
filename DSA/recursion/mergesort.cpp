#include<iostream>
using namespace std;
void display(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<' ';
    }
}
void mergesort(int *p,int c,int n)
{
    if(c>=n)
    {
        return;
    }
    int mid=(c+n)/2;
    mergesort(p,c,mid);
    mergesort(p,mid+1,n);
    int *a=new int[n-c+1];
    int i,j,k;
    for( k=0,i=c,j=mid+1;i<=mid&&j<=n;k++)
    {
        if(p[i]>p[j])
        {
             a[k]=p[j];
             j++;
        }
        else
        {
             a[k]=p[i];
             i++;
        }
    }

    while(i<=mid)
    {
        a[k]=p[i];
        i++;
        k++;
    }
     while(j<=n)
    {
        a[k]=p[j];
        j++;
        k++;
    }
    for(int i=c;i<=n;i++)
    {
        p[i]=a[i-c];
    }
    delete []a;

}

int main()
{
    int n;
    cin>>n;
    int *p=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int c=0;
    mergesort(p,c,n-1);
    display(p,n);
    delete []p;
}
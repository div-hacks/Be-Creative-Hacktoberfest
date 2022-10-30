#include<iostream>
using namespace std;
void display(int *p,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<' ';
    }
}
void swap(int *a,int *b)
{
    int temp=a[0];
    a[0]=b[0];
    b[0]=temp;
}
int partition(int *p,int c,int n)
{
    int count=0;
    for(int i=c+1;i<=n;i++)
    {
        
        if(p[i]<p[c])
        {
            count++;
        }
    }
        swap(p+c,p+c+count);
        int i=c,j=n;
        while(i<c+count&&j>c+count)
        {
            if(p[i]<p[c+count])
            {
                i++;
            }
            else if(p[j]>=p[c+count])
            {
                j--;
            }
            else
            {
                swap(p+i,p+j);
            }
        }
            return count;
        
 }

    

void quicksort(int *p,int c,int n)
{
    if(c>=n)
    {
        return;
    }
    int y=partition(p,c,n);
    quicksort(p,c,c+y-1);
    quicksort(p,c+y+1,n);
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
    quicksort(p,c,n-1);
    display(p,n);
}
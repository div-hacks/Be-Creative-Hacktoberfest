#include<iostream>
using namespace std;
void dremove(char *a)
{
    if(a[0]=='\0')
    {
        return;
    }
    if(a[0]==a[1])
    {
        int i=0;
        while(a[i]!='\0')
        {
            a[i]=a[i+1];
            i++;
        }
        dremove(a);

    }
    else
    {
        dremove(a+1);
       
    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
      dremove(a);
      cout<<a;

}
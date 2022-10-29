#include<iostream>
using namespace std;
void display(char *a)
{    int i=0;
    while(a[i]!='\0')
    {
          cout<<a[i];
          i++;
    }
}
void replace(char *a,char c1,char c2)
{
    if(a[0]=='\0')
    {
        return;
    }

    if(a[0]==c1)
    {
        a[0]=c2;
        replace(a+1,c1,c2);
    }
    else
    {
         replace(a+1,c1,c2);
    }
}
int main()
{
    char a[100];
    cin.getline(a,100);
    char c1,c2;
    cin>>c1>>c2;
    replace(a,c1,c2);
    display(a);
}
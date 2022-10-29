#include<iostream>
using namespace std;

int rkeypad(int n,string *output)
{
    if(n==0)
    {
        output[0]="";
        return 1;
    }
    int a=n%10;
    int b=n/10;
    int smalloutputsize=rkeypad(b,output);
    string k;
    int times;
    switch(a)
    {
        case 0:
        k="";
        times=1;
        break;
        case 1:
        k="";
        times=1;
        
        break;
        case 2:
        k="abc";
        times=3;
        break;
        case 3:
        k="def";
         times=3;
        break;
        case 4:
        k="ghi";
         times=3;
        break;
        case 5:
        k="jkl";
 times=3;
        break;
        case 6:
        k="mno";
         times=3;
        break;
        case 7:
        k="pqrs";
         times=4;
        break;
        case 8:
        k="tuv";
         times=3;
        break;
        case 9:
        k="wxyz";
     times=4;
        break;
        default:
        break;
    }
    int u=output[0].size();
     for(int i=0;i<smalloutputsize*times;)
     {
         for(int j=0;j<times;j++)
         {
             for(int h=0;h<smalloutputsize;h++)
             {
                 output[i]=output[h].substr(0,u)+k[j];
                 i++;
             }
         }
     }
     return smalloutputsize*times;


}
int main()
{
    int n;
    cin>>n;
    string* output=new string[1000];
    int count=rkeypad(n,output);
    for(int i=0;i<count;i++)
    {
        cout<<output[i]<<endl;
    }
}
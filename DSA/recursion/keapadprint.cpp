#include<iostream>
using namespace std;

void rkeypad(int n,string output)
{
    if(n==0)
    {
        
        cout<<output<<endl;
        return;
    }
    int a=n%10;
    
    int b=n/10;
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
    if(times==0||times==1)
    {
        output=output+k;
        rkeypad(b,output);
    }
    if(times==3||times==4)

    {for(int i=0;i<times;i++){
         string copy=output;
         output=output+k.substr(i,1);
         rkeypad(b,output);
         output=copy;
         
    }
    }
    //int u=output[0].size();
     /*for(int i=0;i<smalloutputsize*times;)
     {
         for(int j=0;j<times;j++)
         {
             for(int h=0;h<smalloutputsize;h++)
             {
                 output[i]=output[h].substr(0,u)+k[j];
                 i++;
             }
         }
     }*/
   //*  return smalloutputsize*times;


}
int main()
{
    int n;
    cin>>n;
    string output;
    output="";
    rkeypad(n,output);
   }
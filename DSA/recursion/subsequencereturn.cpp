#include<iostream>
using namespace std;

int retsubs(string input,string *output)
{
    if(input=="")
    {
        output[0]="";
        return 1;
    }
    int smalloutputsize=retsubs(input.substr(1),output);
    for(int i=smalloutputsize;i<2*smalloutputsize;i++)
    {
        output[i]= input[0]+output[i-smalloutputsize];
    }
    return 2*smalloutputsize;
}
int main()
{
    string input;
    cin>>input;
    string *output=new string[1000];
    int n=retsubs(input,output);
    for(int i=0;i<n;i++)
    {
        cout<<output[i]<<endl;
    } 
}
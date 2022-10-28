#include<iostream>
using namespace std;
int i=0;
void printsubs(string input,string output)
{
    if(input=="")

    {
        cout<<output<<++i<<endl;
        return;

    }
    string copy=output;
    output=output+input.substr(0,1);
    printsubs(input.substr(1),output);
    output=copy;
    printsubs(input.substr(1),output);


}
int main()
{
    string input;
    cin>>input;
    string output;
    output="";
    printsubs(input,output);
}
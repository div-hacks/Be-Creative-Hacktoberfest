
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int top=-1;
void push(vector<int> &v, int x){
    top++;
    v[top] = x;
}
void pop(vector<int> &v){
    top--;
}
void peek(vector<int> &v){
    return v[top];
}
void size(vector<int> &v){
    return top+1;
}
void isEmpty(){
    return top==-1;
}
int main()
{
    vector<int> v(5);

    return 0;
}

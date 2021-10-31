#include "bits/stdc++.h"
using namespace std;

void solve(int ip, string op, vector<string>& ans) {
        if(ip == 0) {
            ans.push_back(op);
            return;
        }
        else if(ip < 0) {
            return;
        }
        
        string op1 = "1" + op;
        string op2 = "2" + op;
        string op3 = "3" + op;
        
        solve(ip-1, op1, ans);
        solve(ip-2, op2, ans);
        solve(ip-3, op3, ans);
        
}

int main() {
    int n; 
    cin >> n;
    
    vector<string> ans;
    solve(n,"",ans);
    
    sort(ans.begin(),ans.end());

    // Here I'm printing the result in the formt required by the Pepcoding Judge:
    
    cout<<"[";
    for(int i=0; i<ans.size(); i++) {
        string tmp = ans[i];
        if(i>0) cout<<" ";
        cout<<tmp;
        if(i<ans.size()-1) cout<<",";
    }
    cout<<"]";
}
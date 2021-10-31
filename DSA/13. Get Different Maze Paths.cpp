#include<bits/stdc++.h>             // Accepted, but one test case given is wrong. given : 53, correct : 5 3
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
void getMazePaths(int sr, int sc, string op, int dr, int dc, vector<string>& ans) {

    if(sr == dr and sc == dc) {
        ans.push_back(op);
        return;
    }

    string op1 = "h" + op;
    string op2 = "v" + op;

    if(sr<dr) getMazePaths(sr+1,sc,op1,dr,dc,ans);
    if(sc<dc) getMazePaths(sr,sc+1,op2,dr,dc,ans);

}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans;
    getMazePaths(0,0,"",n-1,m-1,ans);
    sort(ans.begin(), ans.end());
    display(ans);

    return 0;
}
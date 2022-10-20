// Here I implement a Graph in Adjacency matrix 


#include<bits/stdc++.h>

using namespace std;

int main(){
    // Taking total number of nodes 
    int n; cin>>n;
    //Taking input of number of edges 
    int m; cin>>m;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        // edge x-> y

        int x,y; cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // Then according to the question you can use bfs and dfs solutions.
    return 0;
}
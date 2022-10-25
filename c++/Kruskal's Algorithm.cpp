#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int u,v,wt;
    node(int i,int j,int k){
        u=i;
        v=j;
        wt=k;
    }
};
bool cmp(node u,node v){
    return u.wt<v.wt;
}

int findPar(int u,vector<int>&par){
    if(u==par[u]) return u;
    return par[u]=findPar(par[u],par);
}

void unionn(int u,int v,vector<int>&par,vector<int>&rank){
    u=findPar(u,par);
    v=findPar(v,par);
    if(rank[u]<rank[v]){
        par[u]=v;
    }
    else if(rank[v]<rank[u]){
        par[v]=u;
    }
    else{
        par[u]=v;
        rank[v]++;
    }
}
int main(){
	int N=5,m=6;
	vector<node> edges; 
	edges.push_back(node(0,1,2));
	edges.push_back(node(0,3,6));
	edges.push_back(node(1,0,2));
	edges.push_back(node(1,2,3));
	edges.push_back(node(1,3,8));
	edges.push_back(node(1,4,5));
	edges.push_back(node(2,1,3));
	edges.push_back(node(2,4,7));
	edges.push_back(node(3,0,6));
	edges.push_back(node(3,1,8));
	edges.push_back(node(4,1,5));
	edges.push_back(node(4,2,7));
	sort(edges.begin(),edges.end(),cmp);
	vector<int>rank(N,0);
	vector<int>par(N);
	for(int i=0;i<N;i++){
	    par[i]=i;
	}
	vector<pair<int,int>>mst;
	int sum=0;
	for(auto it:edges){
	    if(findPar(it.u,par)!=findPar(it.v,par)){
	        sum+=it.wt;
	        mst.push_back({it.u,it.v});
	        unionn(it.u,it.v,par,rank);
	    }
	}
	cout<<sum<<endl;
}

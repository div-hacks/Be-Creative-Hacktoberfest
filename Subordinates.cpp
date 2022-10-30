// Given the structure of a company, your task is to calculate for each employee the number of their subordinates.

// Input

// The first input line has an integer n: the number of employees. The employees are numbered 1,2,…,n, and employee 1 is the general director of the company.

// After this, there are n−1 integers: for each employee 2,3,…,n their direct boss in the company.

// Output

// Print n integers: for each employee 1,2,…,n the number of their subordinates.

// Constraints
// 1≤n≤2⋅105
// Example

// Input:
// 5
// 1 1 2 3

// Output:
// 4 1 1 0 0

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<set>
#include<stack>
#include<deque>
#include<algorithm>
#include<iomanip>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<climits>
#include<functional>
#include<utility>
#include<assert.h>
#include<deque>
#include<ctime>
#include<complex>
#include<iterator>
 
 
#define ll long long 
#define pb push_back
#define lld long long double
#define ull unsigned long long
#define mp make_pair
#define ull unsigned long long
#define ui unsigned int
#define f first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define INF 1e18
 
using namespace std;
 
const int N=1000006;
const ll mod= 1e9+10;
 
/*---------------<DEBUGGING TEMPLATE>------------------------------------------- */
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif
 
 
void _print(int a){cerr<<a;}
void _print(double a){cerr<<a;}
void _print(char a){cerr<<a;}
void _print(string a){cerr<<a;}
void _print(bool a){cerr<<a;}
void _print(long long a){cerr<<a;}
void _print(long double a){cerr<<a;}
void _print(float a){cerr<<a;}
void _print(ull a){cerr<<a;}
 
template <class T,class V> void _print(pair<T,V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T,class V> void _print(map <T,V> v);
template <class T,class V> void _print(pair<T,V> p){cerr<<"{";_print(p.first);cerr<<",";_print(p.second);cerr<<"}";}
template<class T,class V> void _print(map<T,V> v){cerr<<"[";for(T i: v){_print(i);cerr<<" ";}cerr<<"]";}
template<class T> void _print(set<T> s1){cerr<<"[ ";for(T i: s1){_print(i);cerr<<" ";}cerr<<"]";}
template<class T> void _print(multiset<T> s1){cerr<<"[ ";for(T i: s1){_print(i);cerr<<" ";}cerr<<"]";}
template <class T> void _print(vector<T> v1){cerr<<"[ ";for(T i: v1){_print(i);cerr<<" ";}cerr<<"]";}
 
/*-----------------------------------------------------------------------------------------------------------------------*/
/*---------------------------<SOME UTILITY FUNCTION>--------------------------------------------------------------------- */
 
ll expo(ll a,ll b, ll mod) { ll res=1; while(b>0) {if(b&1)res=(res*a)%mod; a=(a*a)%mod; b=b>>1;} return res;}
void precision(int a){ cout<<setprecision(a)<<fixed;}
ll mminvprime(ll a,ll b){ return expo(a,b-2,b);}
ll moduloAdd(ll a,ll b,ll m){ a=a%m; b=b%m; return (((a+b)%m)+m)%m;}
ll moduloSub(ll a,ll b,ll m){ a=a%m; b=b%m; return (((a-b)%m)+m)%m;}
ll moduloMul(ll a,ll b,ll m){ a=a%m; b=b%m; return (((a*b)%m)+m)%m;}
ll moduloDiv(ll a,ll b,ll m) {a= a%m; b=b%m; return (moduloMul(a,mminvprime(b,m),m)+m)%m;}
 
/*------------------------------------------------------------------------------------------------------------------------ */
/*--------------< CHAL GURU HOJA SHURU>------------------------------------------------------------------------------------- */
 
vector<int> arr[N];
int ans[N];
void dfs(int u,int p){
	ans[u]=1;
 
	for(auto i: arr[u]){
		if(i!=p){
			dfs(i,u);
			ans[u]+=ans[i];
		}
	}
}
void solve(){
	int n; cin>>n;
 
	for(int i=2;i<=n;i++){
		int x; cin>>x;
		arr[i].pb(x);
		arr[x].pb(i);
	}
 
	dfs(1,0);
 
	for(int i=1;i<=n;i++){
		cout<<ans[i]-1<<" ";
	}
	cout<<"\n";
}
int main(){
 
	#ifndef ONLINE_JUDGE
	   freopen("input.txt","r",stdin);
	   freopen("output.txt","w",stdout);
	   freopen("Error.txt","w",stderr);
	#endif
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}
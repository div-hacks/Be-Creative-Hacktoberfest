
// AtCoder Dp contest problem C - Vacation solution 

#include<bits/stdc++.h>
using namespace std;
 
int go(int day,int last,vector<vector<int>>& arr,vector<vector<int>>& dp){
	if(dp[day][last]!=-1) return dp[day][last];
 
	if(day==0){
		int maxi=0;
 
		for(int i=0;i<=2;i++){
			if(i!=last){
				maxi= max(maxi,arr[0][i]);
			}
		}
		return dp[day][last]=maxi;
	}
	int maxi=0;
 
	for(int i=0;i<=2;i++){
		if(i!=last){
			int activity= arr[day][i]+go(day-1,i,arr,dp);
			maxi=max(maxi,activity);
		}
	}
	return dp[day][last]=maxi;
}
int vacation(vector<vector<int>>& arr,int n){
	vector<vector<int>> dp(n,vector<int>(4,-1));
	return go(n-1,3,arr,dp);
}
int main(){
	#ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
  #endif
     int n; cin>>n;
 
     vector<vector<int>> arr(n,vector<int>(3));
 
     for(int i=0;i<n;i++){
     	for(int j=0;j<3;j++){
     		cin>>arr[i][j];
     	}
     }
 
     cout<<vacation(arr,n);
     cout<<"\n";
     return 0;
}
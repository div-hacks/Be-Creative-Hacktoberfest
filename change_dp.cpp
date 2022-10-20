// No. of coins required to constitute the given amt
#include <bits/stdc++.h>
using namespace std;
int main(){
vector <int> coins={1,3,4};
int amt; cin>>amt; 
vector<int> dp(amt+1,INT_MAX);
dp[0]=0;
for (int i=0;i<coins.size();i++){
  for (int j=coins[i]; j<=amt; j++){
    dp[j]=min(dp[j],1+(dp[j-coins[i]]));
  }
}
cout<<dp[amt];
return 0;
}

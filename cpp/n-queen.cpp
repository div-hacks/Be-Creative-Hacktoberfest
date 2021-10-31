//https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        // code here vector<vector<int>>res(n,vector<int>(n,0));
         vector<vector<int>>res(n,vector<int>(n,0));
        vector<vector<int>>ans;
        vector<int>row(n,0);
        vector<int> upper(2*n,0);
       // memset(upper,0,sizeof upper);
       vector<int> lower(2*n,0);
       // memset(lower,0,sizeof lower);
        solveit(res,0,n,ans,row,upper,lower);
        sort(ans.begin(),ans.end());
        return ans;
    }
    
 bool  solveit(vector<vector<int>>&res,int col,int n,vector<vector<int>>&ans,vector<int> &row,vector<int>& upper,vector<int>& lower)
    { 
        if(col==n)
        { vector<int>v;
            for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                    if(res[i][j]==1)
                    v.push_back(j+1);
                }
                
        }
            
            ans.push_back(v);
            return true;
        }
     
        
        
        for(int i=0;i<n;i++)
    {
        if(row[i]==0&&upper[n-1+col-i]==0&&lower[i+col]==0)
        {res[i][col]=1;
        row[i]=1;
        upper[n-1+col-i]=1;
        lower[i+col]=1;
        solveit(res,col+1,n,ans,row,upper,lower);
        res[i][col]=0;
         row[i]=0;
        upper[n-1+col-i]=0;
        lower[i+col]=0;
        }
        
    }
       
       return false;
        
    }
    
    
 
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends

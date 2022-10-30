//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        unordered_map<int,int>mp;
        int csum=0;
        int res=0;
        for(int i=0;i<n;i++){
            csum+=a[i];
            if(csum==0)
            {
                res=max(res,i+1);
            }
            else{
                if(mp.find(csum)!=mp.end())
                {
                    res=max(res,i-mp[csum]);
                }
                else{
                    mp[csum]=i;
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
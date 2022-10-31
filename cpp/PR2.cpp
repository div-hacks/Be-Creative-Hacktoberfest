class Solution {
public:
    int climbStairs(int n) 
    {
        // if(n==1)
        //     return 1;
        // if(n==0)
        //     return 1;
        // int l= climbStairs(n-1);
        // int r=climbStairs(n-2);
        // return(l+r);
        
//         TABLATION
        
        //  vector<int>dp(n+1,-1);
        // dp[0]=1;
        // dp[1]=1;
        // for(int i=2;i<=n;i++)
        // {
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        
//       SPACE OPTIMIZED  
        
    int prev2=1;
        int prev=1;
        int curr;
        for(int i=2;i<=n;i++)
        {
            curr=prev2+prev;
            prev2=prev;
            prev=curr;
            
        }
        return prev;
        
    }
};

class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp)
    {
        // if(ind==0)
        //     return nums[ind];
        // if(ind<0)
        //     return 0;
        // if(dp[ind]!=-1)
        //  return dp[ind];
        int prev=nums[0];
        int prev2=0;
        int cur_i;
        for(int i=1;i<nums.size();i++)
        { 
             int pick = nums[i];
        if(i>1)
            pick += prev2;
        int  nonPick = 0 + prev;
        
        cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        }
       return prev;
    }
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
       return nums[0];
        vector<int>dp(n+1,-1);
        vector<int>temp1,temp2;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        return max (solve(n-1,temp1,dp), solve(n-1,temp2,dp));
    }
};

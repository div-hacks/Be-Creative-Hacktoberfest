class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int sum=0;
        int maxi=INT_MIN;
        unordered_map<int,int>mpp;
        for( int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i]; 
            int rem=sum%k;
            if(i!=0 and rem==0)
                return true;
            else
            {
                if(mpp.find(rem)!=mpp.end())
                {
                 if   (i-mpp[rem]>=2)
                     return true;
                }
                else
                    mpp[rem]=i;
            }
        }
        return false;
    }
};

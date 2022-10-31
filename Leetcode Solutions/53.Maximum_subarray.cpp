/*Given an integer array nums, find the subarray which has the largest sum and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104*/

//OPTIMUM SOLUTION

#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxsum = INT_MIN,sum=0;
        int max1 = INT_MIN;
        
        for(int i =0 ; i < nums.size();i++){
            
           sum +=nums[i];
            if(sum<0){
                
                sum=0;
            }
            maxsum = max(sum, maxsum);
        }
        if(maxsum==0){
            
            for(int i = 0 ; i < nums.size(); i++){
                
                if(nums[i]>max1){
                max1 = nums[i];
               }
                
            }
            return max1 ; 
        }
        
        return maxsum;
            
    }
};
//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int n = Integer.parseInt(read.readLine().trim());
            String arr[] = read.readLine().trim().split(" ");

            Solution ob = new Solution();
            System.out.println(ob.longestCommonPrefix(arr, n));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    String longestCommonPrefix(String A[], int n){
        // code here
        String ans="";
        String sm=Arrays.stream(A).min(Comparator.comparingInt(String::length)).get();
        for(int i=sm.length()-1;i>=0;i--){
            int c=0;
            for(var v:A){
                ans=sm.substring(0,i+1);
                if(v.substring(0,i+1).contains(ans))++c;
            }
            if(c==n) return sm.substring(0,i+1);
        }
        return "-1";
    }
}

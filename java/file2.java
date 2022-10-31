//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int N = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            long ans = obj.NoOfChicks(N);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
     public long NoOfChicks(int N)
    {
        // Code here
        long[] newChik = new long[N+1];
        int cnt = 1;
        long total =1;
        newChik[0] = 1;
        while (cnt < N ){
            if (cnt >=6){
                total = total - newChik[cnt-6] ; // Take out the dead from total
            }
            newChik[cnt]= total*2; // Keep the new addition in a array
            total = total + (total*2); 
            cnt++;
        }
        return total;
    }
}

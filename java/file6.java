//{ Driver Code Starts
//Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(read.readLine().trim());
        while(T-->0)
        {
            int N = Integer.parseInt(read.readLine());
            String input_line[] = read.readLine().trim().split("\\s+");
            int arr[]= new int[N];
            for(int i = 0; i < N; i++)
                arr[i] = Integer.parseInt(input_line[i]);
            Solution ob = new Solution();
            int[] ans = ob.leafNodes(arr, N);
            for(int i = 0; i < ans.length; i++)
            {
                System.out.print(ans[i] + " ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution
{
    
    public int[] leafNodes(int arr[], int N)
    {
        // code here
        if(N <= 1)
            return arr;
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        list = getNodes(arr, 0, N-1, list);
        int[] ans = new int[list.size()];
        
        for(int i=0; i<list.size(); i++){
            ans[i] = list.get(i);
        }
        return ans;
    }
    ArrayList<Integer> getNodes(int[] arr,int l, int r, ArrayList<Integer> list){
        if(l == r){
            list.add(arr[l]);
            return list;
        }
        
        for(int i=l+1; i<=r; i++){
            if(arr[l] < arr[i]){
                list = getNodes(arr, l+1, i-1, list);
                list = getNodes(arr, i, r, list);
                break;
            }
            else if(i == r)
                list = getNodes(arr, l+1, r, list);
        
        }
        return list;
    }
}

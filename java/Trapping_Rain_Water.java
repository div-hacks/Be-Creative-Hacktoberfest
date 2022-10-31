//{ Driver Code Starts
import java.io.*;
import java.util.*;
import java.lang.*;


public class Trapping_Rain_Water {

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim()); //Inputting the testcases
		while(t-->0){
		  
		    //size of array
		    int n = Integer.parseInt(br.readLine().trim());
		    int arr[] = new int[n];
		    String inputLine[] = br.readLine().trim().split(" ");
		    
		    //adding elements to the array
		    for(int i=0; i<n; i++){
		        arr[i] = Integer.parseInt(inputLine[i]);
		    }
		    
		    Solution obj = new Solution();
		    
		    //calling trappingWater() function
		    System.out.println(obj.trappingWater(arr, n));
		}
	}
}


class Solution{
    
    static long trappingWater(int arr[], int n) { 
        long sum = 0;
        int []left = new int[arr.length];
        int []right = new int[arr.length];
        int max = arr[0];
        for(int i = 0; i < arr.length; i++){
            max = Math.max(max, arr[i]);
            left[i] = max;
        }
        int max1 = arr[arr.length-1];
        for (int i = arr.length - 1; i >= 0; i--){
            max1 = Math.max(max1, arr[i]);
            right[i] = max1;
        }

        for (int i = 0; i < arr.length; i++) {
            sum += Math.min(left[i], right[i]) - arr[i];
        }

        return sum;
    } 
}



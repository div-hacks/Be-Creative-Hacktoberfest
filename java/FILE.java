//{ Driver Code Starts

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            int N = Integer.parseInt(read.readLine());
            
            String S[] = read.readLine().split(" ");
            int[] A = new int[N];
            
            for(int i=0; i<N; i++)
                A[i] = Integer.parseInt(S[i]);

            Solution ob = new Solution();
            int[] ptr = ob.satisfyEqn(A,N);
            
            System.out.println(ptr[0] + " " + ptr[1] + " " + ptr[2] + " " + ptr[3]);
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution {
    static int[] satisfyEqn(int[] A, int N) {
        // code here
        int arr[] = {-1,-1,-1,-1};
        
        for(int a =0;a<N;a++){
            for(int b=a+1;b<N;b++){
                for(int c =0; c<N;c++){
                    for(int d = c+1 ; d<N;d++){
                        
                        if(!(a<b && a<c && c<d && b!=c && b!=d) ){
                           continue; 
                        }
                        if(A[a]+A[b] == A[c]+A[d]){
                            arr[0]=a;
                            arr[1]=b;
                            arr[2]=c;
                            arr[3]=d;
                            
                            return arr;
                        }
                        
                    }
                }
            }
        }
        
        return arr;
        
        
    }
};

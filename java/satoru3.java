//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])throws IOException
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    String A = sc.next();
                    String B = sc.next();
                    Solution ob = new Solution();
                    System.out.println(ob.UncommonChars(A, B));
                }
        }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    String UncommonChars(String A, String B)
    {
        // code here
        String s=String.valueOf(-1);
        if(A.equals(B)) return s;
        int flag=0;
        String a="";
        HashMap<Character,Integer> map = new HashMap<>();
        for(int i=0;i<A.length();i++)
        {
           // if(map.containsKey(A.charAt(i)))
            //{
            //    continue;
           // }
           // else{
            map.put(A.charAt(i),1);
           // }
        }
        for(int i=0;i<B.length();i++)
        {
            if(map.containsKey(B.charAt(i)))
            {  if(map.get(B.charAt(i))==1)
                    map.put(B.charAt(i),-1);
            }
            else{
                map.put(B.charAt(i),2);
            }
        }
        
        for (Map.Entry<Character,Integer> entry : map.entrySet()) 
        {
            if(entry.getValue()!=-1)
            {
                flag++;
                a=a+entry.getKey();
            }
            
        }
       char charArray[] = a.toCharArray();
       Arrays.sort(charArray);
 
       if(flag==0) return s;
       
        return new String(charArray);
        
    }
}

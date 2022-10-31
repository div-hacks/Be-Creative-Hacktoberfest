//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int n = Integer.parseInt(in.readLine());
            String contact[] = in.readLine().trim().split("\\s+");
            String s = in.readLine();
            
            Solution ob = new Solution();
            ArrayList<ArrayList<String>> ans = ob.displayContacts(n, contact, s);
            for(int i = 0;i < ans.size();i++){
                for(int j = 0;j < ans.get(i).size();j++)
                    System.out.print(ans.get(i).get(j) + " ");
                System.out.println();
            }
        }
    }
}
// } Driver Code Ends

class Solution{
    
  static class TrieNode{
        // TrieNode[] child = new TrieNode[26]; 
         HashMap<Character,TrieNode> child;
        boolean leaf;
        
        public TrieNode(){
            child = new HashMap<Character,TrieNode>();
  
        // Initialize all the Trie nodes with NULL
         for (char i = 'a'; i <= 'z'; i++)
             child.put(i,null);
  
        leaf = false;
        }
    }
   
   static ArrayList<String>  displayContactsUtil(TrieNode root, String prefix, ArrayList<String> list){
       if(root.leaf == true) {
           list.add(prefix);
       }
       
      for (char i = 'a'; i <= 'z'; i++){
           TrieNode childNode = root.child.get(i);
        
           if(childNode != null)
             displayContactsUtil(childNode,prefix + i,list);
       }
        return list;
   }
    
    static ArrayList<ArrayList<String>> displayContacts(int n, String dict[], String s)
    {
        // code here
         TrieNode root = new TrieNode();
        for(int i=0;i<n;i++){
            insertNode(root, dict[i]);
        }
        
        ArrayList<ArrayList<String>> ans = new ArrayList<>();
        String prefix = "";
        int len = s.length();
        int i;
        for( i=0;i<s.length();i++){
            prefix += s.charAt(i);
            ArrayList<String> list = new ArrayList<>();
            
            char ch = prefix.charAt(i);
            
            TrieNode node = root.child.get(ch);
            if(node == null) {
                list.add("0"); ans.add(list);
                i++;
                break;
            }
            
            displayContactsUtil(node, prefix, list);
            
            
            if(list.size() == 0) 
            { list.add("0"); ans.add(list); }
            else
            ans.add(list);
            root = node;
        }
        
        // THIS is USED if the last char's of the String are not found in the Trie.
        for ( ; i < len; i++)
        {
            ArrayList<String> list = new ArrayList<>();
            list.add("0");
            ans.add(list);
          
        }
        return ans;
    }
    
   static void insertNode(TrieNode root, String word){
        int len = word.length();
        TrieNode current = root;
        
        for(int i=0;i<word.length();i++){
            Character ch = word.charAt(i);
             TrieNode nextNode = current.child.get(ch);
            if(current.child.get(ch) == null ){
                nextNode = new TrieNode();
                current.child.put(ch, nextNode);
            }
            current  = nextNode;
             if (i == len - 1)
                current.leaf = true;
        }
    }
 
}

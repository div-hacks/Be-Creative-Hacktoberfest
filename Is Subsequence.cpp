class Solution {
    public boolean isSubsequence(String s, String t) {
    
        int r=s.length();
        int rr=t.length();
        if(r>rr)
            return false;
        
        int i=0; int j=0;
        while(i<r && j<rr) 
        {char a=s.charAt(i);
             char b=t.charAt(j);
                if(a==b)
                    
        i++;
        j++;
            }
        return i==r? true: false;
                
        }
        
    }



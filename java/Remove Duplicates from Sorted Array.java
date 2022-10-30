class Solution {
    public int removeDuplicates(int[] a) {
     int og=a[0]; int target=1; int l=a.length; 
        if(l==0) 
            return 0;
        for(int i=1;i<l;i++)
        {
            if(og!=a[i])
            {og=a[i];
            a[target]=a[i];
            target++;
            }
        } return target;
        }
        
    }

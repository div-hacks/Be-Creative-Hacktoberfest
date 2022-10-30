// T/C: O(nlogn), S/C: O(1)
int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	int count=0, i=0, j=0, res=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                count++;
                res = max(res, count);
                i++;
            }else{
                j++;
                count--;
            }
        }
        return res;
    }
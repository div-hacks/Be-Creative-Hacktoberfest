// T/C: O(nlogn + nm), S/C: O(m) --m is the maximum deadline
static bool cmp(struct Job j1, struct Job j2){
        if(j1.profit>j2.profit){
            return true;
        } 
        else{
            return false;
        }
    }
vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int max_time=0, max_profit=0, count=0;
        for(int i=0; i<n; i++){
            max_time = max(max_time, arr[i].dead);
        }
        vector<int> slots(max_time+1, 0);
        sort(arr, arr+n, cmp);
        for(int i=0; i<n; i++){
            int j=arr[i].dead;
            while(j>0){
                if(slots[j]==0){
                    slots[j]=1;
                    count++;
                    max_profit+=arr[i].profit;
                    break;
                }
                j--;
            }
        }
        vector<int> res(2);
        res[0] = count;
        res[1] = max_profit;
        return res;
    }
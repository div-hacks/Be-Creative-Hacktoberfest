// T/C: O(nlogn), S/C: O(1)
static bool cmp(Item it1, Item it2){
        return double(1.00*it1.value/it1.weight) > double(1.00*it2.value/it2.weight);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, cmp);
        double profit=0;
        for(int i=0; i<n; i++){
            if(W>=arr[i].weight){
                profit+=arr[i].value;
                W = W-arr[i].weight;
            }else{
                profit+= W* double(1.00*arr[i].value/arr[i].weight);
                break;
            }
        }
        return profit;
    }
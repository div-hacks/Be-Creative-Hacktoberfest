// T/C: O(nlogn) --if not sorted
// T/C" O(n) --if sorted
// S/C: O(1)
int findMinimumCoins(int  V) 
{
    int coins[] =  {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int count=0, m = sizeof(coins)/sizeof(coins[0]);
	
	    for(int i=m-1; i>=0; i--){
	        if(V==0){
	            break;
	        }
	        if(coins[i]<=V){
	            count+= V/coins[i];
	            V = V%coins[i];
	        }
	    }
	    return count;
}
class Best_Time_to_sell_Stock {
    public int maxProfit(int[] a) {
        // int locMax=0,locMin=0;
        // int f1=0,f2=0;
        int p=0;
        for(int i=1;i<a.length;i++)
        {
            if(a[i]>a[i-1])
                p+=(a[i]-a[i-1]);
        }
        return p;
    }
}

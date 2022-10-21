class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<pair<int,int>>g[n+1];
        for(auto it:times)
       {
           int a=it[0];
           int b=it[1];
           int wt=it[2];
           g[a].push_back(make_pair(b,wt)); 
       }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int cd=pq.top().first;
            int cn=pq.top().second;
            pq.pop();
                // vector<pair<int,int>>::iterator it;
            for(auto it:g[cn])
            {
                int nd=it.second;
                int nn=it.first;
                if(dis[nn]>cd+nd)
                {
                    dis[nn]=cd+nd;
                    pq.push({dis[nn],nn});
                }
            }
        } int res = 0;
			for (int i = 1; i <= n; i++)
				res = max(res, dis[i]);
			
			return res == INT_MAX ? -1 : res;
    }
};

class Solution {
public:
    void dfs(int n,int vis[],vector<int> adj[],int s)
    {
        vis[n]=1;
        for(auto it:adj[n])
        {
            if(!vis[it])
               dfs(it,vis,adj,s); //s wasn't needed here, it was needed in adj matrix approach
        }
       
    }
    int findCircleNum(vector<vector<int>>& ic) {
       int n=ic.size(); int ctr=0;
        vector<int> adj[n]; int vis[n]; memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
             for(int j=0;j<n;j++)
             {
                 if(ic[i][j]==1 and i!=j)
                 {
                     adj[i].push_back(j);
                     adj[j].push_back(i);
                 }
             }
        } 
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                vis[i]=1;
                dfs(i,vis,adj,n);
                ctr++;
            }
        }
        return ctr;
        
    }
};

// TC  -> O(N) + O(V+2E) Since we are making dfs call for all n nodes and the inner loop will run for dfs times viz partial dfs+partial dfs sums upto nearly total dfs

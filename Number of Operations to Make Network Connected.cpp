class Solution {
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
                dfs(it,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      int a=connections.size();
        if(a<n-1)
            return -1;
             vector<int>adj[n],vis(n,0); 
              int ctr=0;
             for(int i=0;i<a;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<n;i++)
                {
                    if(!vis[i])
                    { ctr++;
                        dfs(i,adj,vis);
                    }
                }
                
                return ctr-1;
                }
};

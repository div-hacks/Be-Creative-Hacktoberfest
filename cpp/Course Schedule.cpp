class Solution {
public:
    bool cyclic(vector<bool> &vis,vector<bool> &dfsvis, vector<int>adj[],int s)
    {
        vis[s]=true;
        dfsvis[s]=true;
        for(auto it:adj[s])
        {
            if(!vis[it])
            { 
                if(cyclic(vis,dfsvis,adj,it))
                return true;
            }
                else if(vis[it] && dfsvis[it])
                    return true;
        }
        dfsvis[s]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int> adj[n];
        
        for(auto it:prerequisites)
        {
            vector<int> v=it;
            int x=v[0];
            int y=v[1];
            adj[y].push_back(x);
        }
        vector<bool> vis(n,false),dfsvis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(cyclic(vis,dfsvis,adj,i))
                    return false;
            }
        } return true;
    }
};

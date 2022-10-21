class Solution {
public:
    bool bi(vector<int> adj[],int src, int color[])
    {
        color[src]=1;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    q.push(it);
                } 
                else if(color[it]==color[node])
                    return  false;
            }
        }  return true; 
    }
    bool check(vector<int> adj[],int n)
    {
        int color[n+1];
        memset(color,-1,sizeof color);
        for(int i=1;i<n;i++)
        {
            if(color[i]==-1)
            { 
                if(!bi(adj,i,color))
                    return false;
            }
        } return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
     for(int i=0; i<dislikes.size(); i++)
    {
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
        adj[dislikes[i][1]].push_back(dislikes[i][0]);
    } 
        if(check(adj,n)) return true;
        return false;
    }
};

class Solution {
public:
    bool bi(int color[],vector<vector<int>> &graph,int src)
    {
        color[src]=1;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        { int node=q.front();
         q.pop();
            for(auto it:graph[node])
            {  if(color[it]==-1)
            {color[it]=1-color[node];
             q.push(it);
            } else if(color[it]==color[node])
                return false;
            }
        } return true;
    }
    bool check(vector<vector<int>> &graph,int n)
    {
        int color[n];
        memset(color,-1,sizeof color);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
                if(!bi(color,graph,i))
                    return false;
        } return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        if(check(graph,graph.size()))
            return true;
        return false;
    }
};

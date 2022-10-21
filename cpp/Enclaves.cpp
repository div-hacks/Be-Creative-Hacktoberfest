class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& g)
    {
        if(i<0 or j<0 or i>=g.size() or j>=g[0].size() or g[i][j]!=1) return;
        g[i][j]=5;
        dfs(i+1,j,g);
        dfs(i-1,j,g);
        dfs(i,j+1,g);
        dfs(i,j-1,g);
    }
    int numEnclaves(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size(); int ctr=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 or j==0 or i==m-1 or j==n-1 and g[i][j]==1)
                    dfs(i,j,g);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            { if(g[i][j]==1)
                ctr++; }
        }
        return ctr;
    }
};

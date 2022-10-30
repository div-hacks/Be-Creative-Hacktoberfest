class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
      int m=grid.size(); int n=grid[0].size();
        int dirX[4]={0, 0, 1, -1};
        int dirY[4]={1, -1, 0, 0};
        vector<vector<int>> v(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                { v[i][j]=0; 
                 q.push({i,j});
                }
            }
        } 
       
            while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int d1=p.first+dirX[i];
                int d2=p.second+dirY[i];
                if(d1>=0 and d1<m and d2>=0 and d2<n and v[d1][d2]==INT_MAX) // and v[d1][d2]==5)
                { 
                    v[d1][d2]=v[p.first][p.second]+1;
                    q.push({d1,d2}); }
                
            }
        } return v;
    }
};

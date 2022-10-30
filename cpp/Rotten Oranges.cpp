class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int dirX[4]={0, 0, 1, -1};
        int dirY[4]={1, -1, 0, 0};
        int m=grid.size(); int n=grid[0].size(); int ans=0; queue<pair<int,int>> q; int fr=0;
        // if(grid[0][0]==0 || grid[0][0]==1)
        //     return -1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            { if(grid[i][j]==2)
                q.push({i,j});
                if(grid[i][j]==1)
                    fr++;
            }
        }
        // q.push({0,0});
        
        while(!q.empty())
        { int sz=q.size();
         for(int i=0;i<sz;i++)
         {  pair<int,int> p=q.front();
         q.pop();
         for(int i=0;i<4;i++)
         {
             int x=p.first+dirX[i];
             int y=p.second+dirY[i];
             if(x>=0 and y>=0 and x<m and y<n and grid[x][y]!=0 and grid[x][y]!=2) //and grid[x][y]==0 or grid[x][y]==1)
             { 
              grid[x][y]=2;
                   fr--;//ans++;
                 q.push({x,y}); 
               
             }
         } 
            } 
         ans++; 
         
        } if(fr!=0)
             return -1; 
        if(ans==0) return 0;
        return ans-1;
    }
};

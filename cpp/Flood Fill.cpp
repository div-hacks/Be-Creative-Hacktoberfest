class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& g,int col,int nc)
    {
        if(i<0 or j<0 or i>=g.size() or j>=g[0].size() or g[i][j]!=col or g[i][j]==nc) return;
         g[i][j]=nc;
         dfs(i+1,j,g,col,nc);
         dfs(i-1,j,g,col,nc);
         dfs(i,j+1,g,col,nc);
        dfs(i,j-1,g,col,nc);
     
    }
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int col) {
        int m=im.size(), n=im[0].size(); int x=im[sr][sc];
       
                     dfs(sr,sc,im,x,col);
         return im;
    }
};

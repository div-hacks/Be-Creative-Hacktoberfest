#include<bits/stdc++.h>     // Accepted

using namespace std;

void floodfill(int row, int col, string op, vector < vector < int >>& visited, vector < vector < int >>& maze) {

    if(row < 0 || col < 0 || row >= maze.size() || col >= maze[0].size() || maze[row][col] == 1 || visited[row][col] == 1) {
        return;
    }

    if(row == maze.size() && col == maze[0].size()) {
        cout<<op<<"\n";
        return;
    }

    visited[row][col] = 1;

    floodfill(row-1,col,op+"t",visited,maze);
    floodfill(row,col-1,op+"l",visited,maze);
    floodfill(row+1,col,op+"d",visited,maze);
    floodfill(row,col+1,op+"r",visited,maze);

    visited[row][col] = 0;

}

int main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> visited(n, vector < int > (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;

    vector < vector < int >> arr(n, vector < int > (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    floodfill(0,0,"",visited,arr);
}
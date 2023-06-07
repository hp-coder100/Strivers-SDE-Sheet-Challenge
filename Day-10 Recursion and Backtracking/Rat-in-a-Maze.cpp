#include <bits/stdc++.h> 
using namespace std;
void solve(int i, int j,int n,  vector<int> &mat, vector<vector<int>> &maze, vector<vector<int>> &ans)
{
  if(i<0 || j<0 || i==n|| j==n || maze[i][j]==0)
    return;
  
  mat[i*n+j] = 1;

  if(i==n-1 && j==n-1){
    ans.push_back(mat);
    return;
  }
  vector<vector<int>> direction ={{0, 1},{0, -1}, {-1, 0}, {1, 0}};
  for(int k=0;k<4;k++){
    int x = i + direction[k][0];
    int y = j + direction[k][1];

    maze[i][j] = 0;
    solve(x, y, n, mat, maze, ans);
    maze[i][j] = 1;

  }

  mat[i*n+j] = 0;


}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<vector<int>> ans;

  if(maze[0][0]==0 || maze[n-1][n-1]==0)return ans;
  vector<int> mat(n*n, 0);
  solve(0, 0, n, mat, maze, ans);
  return ans;
}
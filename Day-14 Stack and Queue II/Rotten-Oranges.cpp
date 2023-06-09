#include<bits/stdc++.h>
using namespace std;
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<int, int>> q;
    int totalOranges = 0;
    int freshOranges = 0;
    int cnt = 0;
    int time=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push(make_pair(i,j));
                totalOranges++;
            }
            else if(grid[i][j]==1){
                freshOranges++;
                totalOranges++;
            }
        }
    }


    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x+1 < n && grid[x+1][y]==1){
                grid[x+1][y]=2;
                cnt++;
                q.push(make_pair(x+1, y));
            }
            if(x-1 >= 0 && grid[x-1][y]==1){
                grid[x-1][y] = 2;
                cnt++;
                q.push(make_pair(x-1, y));
            }

            if(y+1 < m && grid[x][y+1]==1){
                grid[x][y+1] = 2;
                cnt++;
                q.push(make_pair(x, y+1));
            }
            if(y-1 >= 0 && grid[x][y-1]==1){
                grid[x][y-1] = 2;
                cnt++;
                q.push(make_pair(x, y-1));
            }
        }
        if(!q.empty())
        time++;
    }


    return freshOranges==cnt?time:-1;



}
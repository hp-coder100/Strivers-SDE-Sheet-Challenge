#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &grid, int i, vector<int> &vis, vector<int> &ans){
    ans.push_back(i);
    vis[i] = 1;
    for(auto it:grid[i]){
         if(vis[it]!=1){
             dfs(grid, it, vis, ans);
         }   
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> grid(V);
    for(int i=0;i<E;i++){

        grid[edges[i][0]].push_back(edges[i][1]);
        grid[edges[i][1]].push_back(edges[i][0]);
    }

    vector<vector<int>> ans;
    vector<int> vis(V, 0);
    for(int i=0;i<V;i++){
        if(vis[i]!=1){
            vector<int> temp;
            dfs(grid, i, vis, temp);
            ans.push_back(temp);
        }
    }
    return ans;

}
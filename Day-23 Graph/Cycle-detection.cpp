#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>> &adj, int src, int parent, vector<int> &vis){
      vis[src]=1;

     for(auto it:adj[src]){

         if(!vis[it]){

             if(dfs(adj, it,src,vis))

             return true;

         }

         else if(it!=parent)

         return true;

     }

     return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> grid(n+1);
    for(auto e:edges){
        grid[e[0]].push_back(e[1]);

        grid[e[1]].push_back(e[0]);
    }
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(grid, i,-1, vis))return "Yes";
        }
    }
    return "No";

}

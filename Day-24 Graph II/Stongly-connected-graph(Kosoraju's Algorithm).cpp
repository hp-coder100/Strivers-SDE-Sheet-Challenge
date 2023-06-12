#include<bits/stdc++.h>
using namespace std;
void firstDFS(vector<vector<int>> &adj,int i,vector<int> &vis,stack<int> &st){
    vis[i] = 1;
    for(auto it:adj[i]){
        if(!vis[it]){
            firstDFS(adj, it, vis, st);
        }
    }
    st.push(i);
}


void secondDFS(vector<vector<int>> &grid, int i, vector<int> &vis, vector<int> &ans){
    vis[i] =1;
    ans.push_back(i);
    for(auto it:grid[i]){
        if(!vis[it]){
            secondDFS(grid, it, vis, ans);
        }
    }

}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> adj(n);
    for(auto e:edges){
        adj[e[0]].push_back(e[1]);
    }   

    vector<int> vis(n, 0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            firstDFS(adj, i, vis, st);
        }
    }
    vector<vector<int>> grid(n);
    for(int i=0;i<n;i++){
        vis[i] = 0;
        for(auto it:adj[i]){
            grid[it].push_back(i);
        }
    }
    int cnt = 0;
    vector<vector<int>> ans;
    while(!st.empty()){
        int s = st.top();
        st.pop();
        if(!vis[s]){
            vector<int> temp;
            secondDFS(grid, s, vis, temp);
            cnt++;
            ans.push_back(temp);
        }
    }
    return ans;
}
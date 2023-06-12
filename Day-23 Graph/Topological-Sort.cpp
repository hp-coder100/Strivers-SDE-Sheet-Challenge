#include <bits/stdc++.h> 
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Using Kahn's Algorithm -> BFS.
    // Time Complexity: O(V + E)
    // Space Complexity: O(V + E)
    // Build the adj. list
    // Indegree Map
    vector<int> inDegree(v, 0);
    vector<vector<int>> adj(v);
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        inDegree[edge[1]]++;
    }   
    // Visited array
    vector<bool> visited(v, false);
    // Queue
    queue<int> q;
    // Put the nodes with indegree 0
    for(int i = 0; i < v; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    // store the final answer
    vector<int> ans;
    // BFS 
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        visited[curr] = true;
        for(int u : adj[curr]){
            if(visited[u]) continue;
            inDegree[u]--;
            if(inDegree[u] == 0) q.push(u);
        }
    }
        
    return ans;
}
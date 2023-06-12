
#include <bits/stdc++.h>
using namespace std;
class Compare{
    public:
        bool operator()(pair<int, int> a, pair<int, int> b){
            return (a.second > b.second);
        }
};

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Prim's Algorithm
    // Adjacency List
    vector<vector<pair<int, int>>> adj(n + 1);
    for(auto edge : g){
        adj[edge.first.first].push_back(make_pair(edge.first.second, edge.second));
        adj[edge.first.second].push_back(make_pair(edge.first.first, edge.second));
    }
    // Key Array
    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> minHeap;
    vector<int> key(n + 1, INT_MAX);
    // MST Array
    vector<bool> mst(n + 1, false);
    // Parent Array
    vector<int> parent(n + 1, -1);
    // Prim's Algorithm
    // assume 1 as the root node
    key[1] = 0;
    minHeap.push(make_pair(1, 0));
    for(int i = 0; i < n; i++){
        // Step 1: find the minimum key which is not in the mst.
        while(mst[minHeap.top().first]) minHeap.pop();
        int u = minHeap.top().first;
        minHeap.pop();
        // Step 2: mark the minimum node as mst visited
        mst[u] = true;
        // Step 3: travel all it's neighbours and update there keys
        for(auto neighbour : adj[u]){
            if(!mst[neighbour.first] && key[neighbour.first] > neighbour.second){
                key[neighbour.first] = neighbour.second;
                parent[neighbour.first] = u;
            }
            minHeap.push(make_pair(neighbour.first, neighbour.second));
        } 
    }
    vector<pair<pair<int,int>,int>> ans;
    for(int i = 2; i <= n; i++){
        ans.push_back(make_pair(make_pair(i, parent[i]),key[i]));
        // ans.push_back(make_pair(make_pair(parent[i], i),key[i]));
    }
    return ans;
}
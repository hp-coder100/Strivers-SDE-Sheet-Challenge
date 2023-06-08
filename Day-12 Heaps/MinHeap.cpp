
#include <bits/stdc++.h> 

using namespace std;
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0;i<n;i++){

        if(q[i][0]==0){
            pq.push(q[i][1]);
        }
        else{
            ans.push_back(pq.top());
            pq.pop();
        }

    }
    return ans;
}

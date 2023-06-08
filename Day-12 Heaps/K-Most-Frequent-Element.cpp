#include <bits/stdc++.h> 
using namespace std;
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for(auto i:arr){
        mp[i]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    int i=0;
    for(auto i:mp){

        if(k>0){
            pq.push(make_pair(i.second, i.first));
            k--;
        }
        else{
            if(pq.top().first < i.second){
                pq.pop();
                pq.push(make_pair(i.second, i.first));
                
            }
        }

    }

    vector<int> ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
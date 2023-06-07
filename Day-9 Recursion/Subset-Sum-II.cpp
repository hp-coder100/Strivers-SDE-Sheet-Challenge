#include <bits/stdc++.h> 
using namespace std;
void solve(vector<int> &arr, int i, int n,vector<int> curr, set<vector<int>> &st){
    if(i==n){
        sort(curr.begin(), curr.end());
        st.insert(curr);
        return;
    }

    curr.push_back(arr[i]);
    solve(arr, i+1, n, curr, st);
    curr.pop_back();
    solve(arr, i+1, n, curr, st);
}



vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    set<vector<int>> st;
    vector<int> curr;
    solve(arr, 0, n,curr, st);
    for(auto it:st){
        ans.push_back(it);
    }
    return ans;
}
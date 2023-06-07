#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int i, int n, int k, vector<int> curr, vector<vector<int>> &ans){
    if(i==n){
        if(k==0)ans.push_back(curr);
        return ;
    }

    solve(arr, i+1, n, k, curr, ans);

    
    curr.push_back(arr[i]);
    solve(arr, i+1, n, k-arr[i], curr, ans);
    
     

}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    
    vector<int> curr;
    
    solve(arr, 0, n, k, curr, ans);

    return ans;
}
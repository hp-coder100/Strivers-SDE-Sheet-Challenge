#include <bits/stdc++.h> 

using namespace std;
//recursion functoim
void solve(vector<int> &v, int ind,vector<int> &curr, vector<vector<int>> &ans){

    if(ind==v.size()){
        ans.push_back(curr);
        return;
    }
    curr.push_back(v[ind]);
    solve(v, ind+1, curr, ans);
    curr.pop_back();
    solve(v, ind+1, curr, ans);


}

//bit manipulation 
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here

    vector<vector<int>> ans;
    int n = v.size();
    for(int num = 0; num < (1<<n); num++){

        vector<int> curr;
        for(int i=0;i<n;i++){
            if(num&(1<<i)){
                curr.push_back(v[i]);
            }
        }
        ans.push_back(curr);
    }
   
    sort(ans.begin(), ans.end());
    return ans;

}
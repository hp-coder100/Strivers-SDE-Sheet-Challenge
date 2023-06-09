#include <bits/stdc++.h> 
using namespace std;
int solve(vector<int>&arr,int i, int j, vector<vector<int>> &dp){
    
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    
    int mini = INT_MAX;

    for(int k=i;k<j;k++){
        mini = min(mini,  arr[i-1]*arr[k]*arr[j] + solve(arr, i, k, dp)+ solve(arr, k+1, j,dp));
    }

    return dp[i][j]=mini;

}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));


    
    return solve(arr, 1, N-1, dp);




}
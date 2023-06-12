#include <bits/stdc++.h> 
using namespace std;
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{
	// Write your code here
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
		for(int i=0;i<n;i++){
			dp[i][0] = arr[i];
		}
    
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
             dp[i][j+1] = dp[i+1][j +1];
    
    
            if(j == -1 || arr[i] > arr[j]){
                
               dp[i][j+1] =  max(dp[i][j+1], arr[i] + dp[i+1][i+1]);
            }
            }
        }    
        return dp[0][0];
}
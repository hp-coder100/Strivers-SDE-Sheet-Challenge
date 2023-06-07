#include <bits/stdc++.h> 
using namespace std;
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    int ans = 0;
    for(int i=coins.size()-1;i>=0;i--){
        if(amount >= coins[i]){
            ans += amount / coins[i];
            amount = amount % coins[i];
        }
        if(amount==0)break;
    }
    return ans;
}

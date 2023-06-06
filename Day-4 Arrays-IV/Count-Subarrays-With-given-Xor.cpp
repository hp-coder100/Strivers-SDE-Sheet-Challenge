#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n= arr.size();
    int xr = 0;
    unordered_map<int,int> mp;
    mp[xr]++;
    int cnt=0;

    for(int i=0; i<n; i++){
        xr = xr^arr[i];

        int a = xr^x;

        cnt+=mp[a];
        
        mp[xr]++;
    }
    return cnt;
}
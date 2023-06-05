#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int arr[], int n)
{
    long long ans = 0;
    long long cur = 0;
    for(int i=0;i<n;i++){
        cur+= arr[i];
        ans = max(ans, cur);
        if(cur<0)cur = 0;

    }
    return ans;

}
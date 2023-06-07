#include <bits/stdc++.h> 
using namespace std;
long getTrappedWater(long *arr, int n){
    // Write your code here.
    vector<long> prev(n), next(n);
    prev[0] = arr[0];
    next[n-1] = arr[n-1];
    for(int i=1;i<n;i++){
        prev[i] = max(prev[i-1], arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        next[i] = max(next[i+1], arr[i]);
    }
    long ans = 0;
    for(int i=0;i<n;i++){
        ans += min(prev[i], next[i]) - arr[i];
    }
    return ans;

}
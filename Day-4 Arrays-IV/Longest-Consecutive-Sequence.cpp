#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),  arr.end());
    int ans = 1;
    int curr= 1;

    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])continue;
        if(arr[i]==arr[i-1]+1){
            curr++;
        }
        else {
            ans = max(ans, curr);
            curr = 1;
        }
    }
    ans = max(ans,curr);
    return ans;
}
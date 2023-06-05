#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;
    int a=INT_MIN, b=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0 && arr[i]!=b){
            a = arr[i];
            cnt1++;
        }
        else if(cnt2==0 && arr[i]!=a){
            b= arr[i];
            cnt2++;
        }
        else if(arr[i]==a)cnt1++;
        else if(arr[i]==b)cnt2++;
        else {
            cnt1--;
            cnt2--;
        }

        


    }
    cnt2 = 0, cnt1 =0;
        for(int i=0;i<n;i++){
            if(arr[i]==a)cnt1++;
            if(arr[i]==b)cnt2++;
        }
        
        if(cnt1>n/3)ans.push_back(a);
        if(cnt2>n/3)ans.push_back(b);
    return ans;


}
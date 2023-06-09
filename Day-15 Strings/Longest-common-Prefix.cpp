#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    if(n==1)return arr[0];
    string ans = "";
    string ch = arr[0];
    int i=0;
    while(i<ch.size()){
        for(int j=1;j<n;j++){
            if(i>=arr[j].size() || arr[j][i]!= ch[i])return ans;    
        }
        ans +=ch[i++];
    }
    return ans;
}



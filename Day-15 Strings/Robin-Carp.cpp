#include<bits/stdc++.h>
using namespace std;
bool contains(string &a,string &b, int i){
    int j=0;
    while(j<b.size()){
        if(a[i+j]!=b[j++])return false;
    }
    return true;
}

vector<int> stringMatch(string &str, string &pat) {
    // Write your code here

    vector<int> ans;
    int n= str.size();
    int m = pat.size();
    for(int i=0;i<=n-m;i++){
        if(str[i]==pat[0] && contains(str, pat, i))ans.push_back(i);
    }
    return ans;

}

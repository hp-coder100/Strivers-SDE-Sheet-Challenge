#include <bits/stdc++.h>

using namespace std;
void solve(string &s, int ind, vector<string> &ans){
    if(ind==s.size()){
        ans.push_back(s);
        return;
    }

    for(int i=ind; i<s.size();i++){
        swap(s[i], s[ind]);
        solve(s, ind+1, ans);
        swap(s[i], s[ind]);
    }

}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    
    solve(s, 0, ans);

    return ans;
}
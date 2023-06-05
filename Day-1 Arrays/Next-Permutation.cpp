#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int i=n-2;
    int ind = -1;
    while(i>=0){
        if(permutation[i] < permutation[i+1]){
            ind = i;
            break;
        }
        i--;
    }
    if(ind==-1)reverse(permutation.begin(), permutation.end());
    else{
        int mini = ind+1;
        for(i=ind+2;i<n;i++){
            if(permutation[mini] > permutation[i] && permutation[i] > permutation[ind])mini = i;
        }
        swap(permutation[ind], permutation[mini]);
        reverse(permutation.begin()+ind+1, permutation.end());
    }
    return permutation;
}
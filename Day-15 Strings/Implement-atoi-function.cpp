#include <bits/stdc++.h> 
int atoi(string str) {
    // Write your code here.
    int ans = 0;
    int neg = 1;
    if(str[0]=='-')neg = -1;
    for(auto i:str){
        if(i >= '0' && i<='9')
            ans = 10*ans + (i-'0');
    }
    return ans*neg;
}
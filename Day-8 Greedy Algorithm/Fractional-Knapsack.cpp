#include <bits/stdc++.h> 
using namespace std;
bool static comp(pair<int,int> a,pair<int,int> b){
    double x = (double)a.second/(double)a.first;
    double y = (double)b.second/(double)b.first;
    return x > y;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.

    sort(items.begin(), items.end(), comp);

    int currW=0;
    double ans = 0;
    for(int i=0;i<n;i++){
        if(currW + items[i].first <= w){
            
            currW+=items[i].first;
            ans+=items[i].second;
        }
        else{
            int remaining = w-currW;
            ans += ((double)items[i].second/(double)items[i].first)*(double)remaining;
            break;
        }
    }
    return ans;


}
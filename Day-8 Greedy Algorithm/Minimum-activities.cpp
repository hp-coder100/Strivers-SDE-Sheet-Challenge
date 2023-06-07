#include<bits/stdc++.h>
using namespace std;
static bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
    
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n= start.size();
    vector<pair<int, int>> activity(n);
    for(int i=0;i<n;i++){
        activity[i].first = start[i];
        activity[i].second = finish[i];
    }

    sort(activity.begin(), activity.end(), comp);

    int cnt=1;
    int lastActivityEnd = activity[0].second;

    for(int i=1;i<n;i++){
        if(lastActivityEnd <= activity[i].first){
            cnt++;
            lastActivityEnd = activity[i].second;
        }
    }
    return cnt;
}
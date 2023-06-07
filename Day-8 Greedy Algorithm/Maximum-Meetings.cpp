#include <bits/stdc++.h> 
using namespace std;
struct meet{

    int start, end, pos;
};

static bool comp(struct meet m1, meet m2){
    if(m1.end < m2.end)return true;
    else if(m1.end > m2.end) false;
    else if(m1.pos<m2.pos)return true;
    
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n= start.size();
    meet meetings[n];
    for(int i=0;i<n;i++){
       
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i+1;
    }
    sort(meetings, meetings+n, comp);
    vector<int> ans;
    ans.push_back(meetings[0].pos);
    int lastEnd = meetings[0].end;
    for(int i=1;i<n;i++){
        if(lastEnd < meetings[i].start )
        {
            ans.push_back(meetings[i].pos);
            lastEnd = meetings[i].end;
        }
    }
    return ans;
}
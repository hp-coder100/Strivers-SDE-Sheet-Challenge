#include <bits/stdc++.h> 
using namespace std;
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    vector<int> ans;
    stack<int> st;

    for(int i=0;i<price.size();i++)
    {   
        
        while(!st.empty() && price[st.top()] <= price[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(1+i);
        }
        else{
            ans.push_back(i-st.top());
        }
        st.push(i);

    }
    return ans;
}
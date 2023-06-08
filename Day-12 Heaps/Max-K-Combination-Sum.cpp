
#include<bits/stdc++.h>
using namespace std;
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	vector<int> ans;
	
	priority_queue<int, vector<int>, greater<int>> pq;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x = a[i]+b[j];
			if(k>0){
				pq.push(x);
				k--;
			}
			else{
				if(pq.top() < x){
					pq.push(x);
					pq.pop();
				}
			}
		}
	}

	
	while(!pq.empty()){
		ans.push_back(pq.top());
		pq.pop();
	}
	reverse(ans.begin(), ans.end());
	return ans;
	
}
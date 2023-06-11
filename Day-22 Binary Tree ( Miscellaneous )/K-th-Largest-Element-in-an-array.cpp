#include <bits/stdc++.h> 
using namespace std;
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int, vector<int>, greater<int> > pq;
	int i=0;
	while(i<K){
		pq.push(arr[i++]);
	}
	while(i<size){
		if(arr[i] > pq.top()){
			pq.pop();
			pq.push(arr[i]);
		}
		i++;

	}
	return pq.top();
}
#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int start = 1;
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[i-1])arr[start++]=arr[i];
	}
	return start;


}
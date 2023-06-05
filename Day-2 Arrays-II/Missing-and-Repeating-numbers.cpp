#include <bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
	int sum = 0;
	for(int i=0;i<n;i++){
		sum ^= arr[i];
		sum ^= i+1;
	}

	int num = (sum &  ~(sum-1));

	int a=0, b=0;
	for(int i=0;i<n;i++){
		if((num & arr[i])!=0) a ^= arr[i];
		else b ^= arr[i];

		if((num&(i+1))!=0) a ^= i+1;
		else b ^= i+1;
	}

	int cnt = 0;
	for(int i=0;i<n;i++){
		if(a==arr[i])cnt++;
	}
	if(cnt==0)return {a, b};
	return {b, a};


	
}

#include <bits/stdc++.h> 
using namespace std;
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> ans;
	sort(arr.begin(), arr.end());
	for(int i=0;i<n-2;i++){
		if(i!=0 && arr[i]==arr[i-1])continue;
		int sum  = K-arr[i];
		int start = i+1, end = n-1;
		while(start<end){
			int s = arr[start]+arr[end];
			if(s==sum){
				ans.push_back({arr[i], arr[start], arr[end]});
				while(start+1<end && arr[start]==arr[start+1])start++;
				while(start<end-1 && arr[end]==arr[end-1])end--;
				start++;
				end--;
			}
			else if(s>sum){
				end--;
			}
			else start++;
		}

	}
	return ans;
}
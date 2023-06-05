#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cnt = 1;
	int maj = 0;
	for(int i=1;i<n;i++){
		if(arr[i]==arr[maj])cnt++;
		else cnt--;

		if(cnt==0){
			maj = i;
			cnt = 1;
		}
	}
	cnt =0;
	for(int i=0;i<n;i++){
		if(arr[maj]==arr[i])cnt++;
	}
	return cnt> (n/2)?arr[maj]:-1;
}
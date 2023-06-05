#include <bits/stdc++.h>

void insert(vector<int> &arr,int n, int pos, int item){
	
	while(n>=pos){
		arr[n] = arr[n-1];
		n--;
	}

	arr[pos] = item;
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	for(int i=0;i<n;i++){
		int pos= upper_bound(arr1.begin(), arr1.begin()+m, arr2[i])-arr1.begin();
		//cout<<pos<<" "<<arr2[i]<<" "<<m<<endl;
		insert(arr1, m, pos, arr2[i]);
		m++;

		
		
	}
	return arr1;
	

}
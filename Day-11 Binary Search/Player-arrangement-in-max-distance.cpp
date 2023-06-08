#include <bits/stdc++.h> 
using namespace std;
bool isPossible(vector<int> &positions, int n, int m, int mid){

	
  int k = positions[0];
  m--;
  for (int i = 1; i < n; i++) {
    if (positions[i] - k >= mid) {
      m--;
      if (!m) {
        return true;
      }
      k = positions[i];
    }
  }
  return false;


}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int start= 1;
	int end = positions[n-1]-positions[0];

	int ans = -1;
	while(start<=end){

		int mid = start+(end-start)/2;
		
		if(isPossible(positions, n, c, mid)){
			ans = mid;
			start= mid+1;
		}
		else end = mid-1;
	}

	return ans;
}
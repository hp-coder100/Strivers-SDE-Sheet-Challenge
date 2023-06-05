#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long ans = 1;
	long nx = x;
	while(n>0){
		if(n&1){
			ans = ((ans%m)*(nx%m))%m; 
		}

		nx = ((nx%m)*(nx%m))%m;
		n = n>>1;
	}
	return (int)ans%m;
}
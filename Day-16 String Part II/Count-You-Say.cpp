#include <bits/stdc++.h> 
using namespace std;
string solve(string &s){
	if(s.empty())return NULL;
	string ans = "";
	int cnt = 1;char ch =s[0];
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1]){
			cnt++;
		}
		else{
			ans+= to_string(cnt) + ch;
			cnt=1;ch=s[i];
		}
	}
	ans+=to_string(cnt)+ch;
	return ans;

}
string writeAsYouSpeak(int n) 
{
	// Write your code here.
	string ans = "1";
	for(int i=1;i<n;i++){
		ans = solve(ans);
	}
	return ans;	
}
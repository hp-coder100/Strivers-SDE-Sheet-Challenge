#include <bits/stdc++.h> 
using namespace std;
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    unordered_map<int,int>  mp;

   int i = 0 , n = arr.size();

   vector<int> ans;

   for(int j=0;i<=n-k;j++){

    

        mp[arr[j]]++;

       if(j >= k-1){

           ans.push_back(mp.size());

           mp[arr[i]]--;

           if(mp[arr[i]]==0) mp.erase(arr[i]);

           i++;

       }

   }

   return ans;  

}
#include <bits/stdc++.h> 
using namespace std;
vector<int> computeLPS( string p, int m )
{
   int i = 1,
   len = 0;
   vector<int> lps(m,0);
   while ( i < m )
   {
       if ( p[i] == p[len] ){
           len++;
           lps[i] = len;
           i++;
       } else {
           if ( len != 0 ){
               len = lps[len-1];
           } else {
               lps[i] = 0;
               i++;
           }
       }
   }
   return lps;
}

bool KMP( string s, string p ){
   int n = s.size(),m = p.size(),i = 0,j = 0, count = 0;             
   vector<int> lps = computeLPS(p,m);
   while ( i < n ){
       if ( s[i] == p[j] ){
           i++;
           j++;
       } else {
           if ( j != 0 ){
               j = lps[j-1];
           } else {
               i++;
           }
       }
       if ( j == m ){
           count++;
           return true;
           j = lps[j-1];
       }
   }
   return false;
}

bool findPattern(string p, string s)
{
    // Write your code here.
    return KMP(s,p);
}
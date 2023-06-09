#include <bits/stdc++.h> 
using namespace std;
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.size()!=str2.size())return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1==str2;
}
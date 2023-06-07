#include<bits/stdc++.h>
using namespace std;
int search(int* arr, int n, int key) {
    // Write your code here.
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid]==key)return mid;

        if(arr[start] <= arr[mid])
        {
            if(key >= arr[start] and key <= arr[mid]) end = mid-1;
            else start = mid+1;
        }
        else{
            if(key >= arr[mid] and key <= arr[end])start = mid+1;
            else end = mid-1;
        }
    }
    return -1;
}
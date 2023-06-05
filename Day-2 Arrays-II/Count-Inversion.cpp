#include <bits/stdc++.h> 
 
void merge(vector<long long>&arr, long long begin, long long middle, long long end, long long int&count){
    vector<long long>ans;
    long long i = begin;
    long long j = middle+1;
    while(i<=middle && j<=end){
        if(arr[i]>arr[j]){
            ans.push_back(arr[j]);
            count = count+ middle- i+ 1;
            j++;
        }
        else{
            ans.push_back(arr[i]);
            i++;
        }
    }
    while(i<=middle){
        ans.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        ans.push_back(arr[j]);
        j++;
    }
    long long m =0;
    for(long long k=begin; k<=end; k++){
        arr[k] = ans[m];
        m++;
    }

}

void mergesort(vector<long long>&a, long long start, long long stop, long long int&c){
    if(start>=stop){
        return;
    }
    long long mid = (start+ stop)/2;
    mergesort(a, start, mid, c);
    mergesort(a, mid+1, stop, c);
    return merge(a,start, mid, stop, c);
}

long long getInversions(long long *arr, int n){
        long long count = 0;
        vector<long long>ans;
        for(int i=0; i<n; i++ ){
            ans.push_back(arr[i]);
        }
        mergesort(ans, 0, n-1, count);
        return count;
        
}
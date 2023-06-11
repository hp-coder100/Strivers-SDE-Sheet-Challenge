#include <bits/stdc++.h> 
using namespace std;
class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       int i=0;
       while(i<k){
           pq.push(arr[i++]);
       }

        while(i<arr.size()){
            if(arr[i] > pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }


    }

    void add(int num) {
        // Write your code here.
        if(num > pq.top()){
            pq.pop();
            pq.push(num);
        }
    }

    int getKthLargest() {
       // Write your code here.
       return pq.top();
    }

};
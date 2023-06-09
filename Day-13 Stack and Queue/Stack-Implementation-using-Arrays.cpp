#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int arr[1000];
    int tp;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        tp = -1;
        size = capacity-1;
    }

    void push(int num) {
        // Write your code here.
        if(!isFull()){
            arr[++tp] = num;
        }

    }

    int pop() {
        // Write your code here.
        int num = -1;
        if(!isEmpty()){
            num = arr[tp--];
        }
        return num;
    }
    
    int top() {
        // Write your code here.
        int num = -1;
        if(!isEmpty()){
            num = arr[tp];
        }
        return num;
    }
    
    int isEmpty() {
        // Write your code here.
        return tp<0;
    }
    
    int isFull() {
        // Write your code here.
        return tp==size;
    }
    
};
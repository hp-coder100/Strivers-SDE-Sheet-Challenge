#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.size()==0;
    }

    void push(int element) {
        // Implement the push() function.
        int size = q.size();
        q.push(element);
        while(size--){
            q.push(q.front());
            q.pop();
        }

    }

    int pop() {
        if(isEmpty())return -1;
        int ele= q.front();
        q.pop();
        return ele;
        // Implement the pop() function.
    }

    int top() {

        if(isEmpty())return -1;
        return q.front();
        // Implement the top() function.
    }
};
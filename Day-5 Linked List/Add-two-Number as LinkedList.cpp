#include<bits/stdc++.h>
using namespace std;
  class Node {
  public:
       int data;
       Node *next;
       Node() {
           this->data = 0;
           this->next = NULL;
      }
       Node(int data) {
           this->data = data;
           this->next = NULL;
       }
       Node (int data, Node *next) {
           this->data = data;
           this->next = next;
       }
 };



Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* ans = new Node();
    Node* tail = ans;
    int carry = 0;
    while(num1 || num2 || carry>0){
        int sum =0;
        if(num1){
            sum += num1->data;
            num1=num1->next;
            
        }
        if(num2){
            sum += num2->data; 
            num2 = num2->next;
            
        }

        sum +=carry;
        tail->next = new Node(sum%10);
        tail = tail->next;
        carry = sum/10;

        
        }
    return ans->next;


}

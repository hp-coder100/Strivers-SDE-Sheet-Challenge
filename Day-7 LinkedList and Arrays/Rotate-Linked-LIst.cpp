#include<bits/stdc++.h>
using namespace std;
  class Node {
  public:
      int data;
      Node *next;
      Node() : data(0), next(nullptr) {}
      Node(int x) : data(x), next(nullptr) {}
      Node(int x, Node *next) : data(x), next(next) {}
 };
int getLen(Node *head){
     int cnt = 0;
     while(head){
          head=head->next;
          cnt++;
     }
     return cnt;
}
Node *rotate(Node *head, int k) {
     // Write your code here.
     if(k==0 || !head ||!head->next)return head;
     Node *temp = head;
     int cnt = 1;
     int len = getLen(head);
     while(temp->next && cnt++ < len-((k%len))){
          temp = temp->next;
          
     }
     if(temp->next){
          Node *newHead = temp->next;
          
          temp->next = NULL;
          temp = newHead;
          while(temp->next){
               temp = temp->next;
          }
          temp->next=head;
          return newHead;
     }
     return head;
     

}

Node* rotateRight(Node* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
    Node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link last node to first node
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
}
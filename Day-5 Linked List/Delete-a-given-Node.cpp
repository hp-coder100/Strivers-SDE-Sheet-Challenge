#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};



void deleteNode(Node * node) {
    // Write your code here.
    node->data = node->next->data;
    node->next = node->next->next;
    return;


}
/*

Node* reverseHead(Node* head){
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev= curr;
        curr = next;
    }
    return prev;
}
Node* removeKthNode(Node* head, int K)
{
    Node* reverse = reverseHead(head);
    if(K==1)return reverseHead(reverse->next);

    int cnt = 1;
    Node *temp = reverse;
    while(temp && cnt < K-1){
        cnt++;
        temp = temp->next;   
    }
    temp->next = temp->next->next;
    return reverseHead(reverse);


}

*/


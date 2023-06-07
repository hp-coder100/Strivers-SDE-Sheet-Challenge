#include<bits/stdc++.h>
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



Node *firstNode(Node *head)
{
    //    Write your code here.
    if(head==NULL || head->next==NULL)return NULL;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
       
        if(slow==fast)break;
    }
    if(slow!=fast)return NULL;
    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;

    }


    return slow;

}
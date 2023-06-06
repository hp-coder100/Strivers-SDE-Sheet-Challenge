
#include <bits/stdc++.h>

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };



LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    if(!head||!head->next)return head;
    LinkedListNode<int>* temp = head;
    LinkedListNode<int>* prev=NULL;
    LinkedListNode<int>* next=NULL;
    while(temp){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
    
}
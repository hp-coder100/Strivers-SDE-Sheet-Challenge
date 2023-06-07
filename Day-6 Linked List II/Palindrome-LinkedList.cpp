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

LinkedListNode<int>* reverse(LinkedListNode<int>* head){
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    while(curr){
        LinkedListNode<int> *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(!head || !head->next)return true;

    LinkedListNode<int>*slow =head, *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    fast = head;
    while(slow && fast){
        if(slow->data != fast->data)return false;
        slow =  slow->next;
        fast = fast->next;
    }
    
    return true;
    
    
}
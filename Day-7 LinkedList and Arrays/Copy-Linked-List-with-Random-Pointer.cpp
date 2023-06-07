#include <bits/stdc++.h>
using namespace std;
template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> mp;
    LinkedListNode<int> *clone = new LinkedListNode<int> (-1);

    LinkedListNode<int> *Orghead = head;
    LinkedListNode<int> *cloneHead = clone;
    while(Orghead){
        cloneHead->next = new LinkedListNode<int>(Orghead->data);
        cloneHead = cloneHead->next;
        mp[Orghead] = cloneHead;
        Orghead = Orghead->next;
    }
    
    Orghead = head;
    cloneHead = clone->next;

    while(Orghead){
        cloneHead->random = mp[Orghead->random];
        cloneHead = cloneHead->next;
        Orghead = Orghead->next;
    }

    return clone->next;

}

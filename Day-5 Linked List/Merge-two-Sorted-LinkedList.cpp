#include <bits/stdc++.h>
using namespace std;    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int> *finalList=new Node<int>(-1); 
    Node<int> *tail = finalList;
   
    while(first!=NULL || second!=NULL){
        if(first && second){
            
            if(first->data <= second->data){
                tail->next = new Node<int>(first->data);
                tail = tail->next;
                first=first->next;    
            }
            else{ 
                tail->next = new Node<int>(second->data);
                tail = tail->next;
                second = second->next;
            }
        }
        else if(first){
            tail->next = new Node<int>(first->data);
            tail = tail->next;
            first=first->next;
        }
        else{
            tail->next = new Node<int>(second->data);
            tail = tail->next;
            second = second->next;
        }
        
    }
    return finalList->next;
}

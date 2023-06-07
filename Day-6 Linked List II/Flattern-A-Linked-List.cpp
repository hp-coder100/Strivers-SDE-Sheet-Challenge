#include<bits/stdc++.h>
using namespace std;
  class Node {
   public:
 		int data;
 		Node *next;
  		Node *child;
 		Node() : data(0), next(nullptr), child(nullptr){};
 		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
  };
 

 Node* mergeTwoLists(Node* first, Node* second) {
    
    Node *finalList=new Node(-1); 
    Node *tail = finalList;
    while(first!=NULL || second!=NULL){
        if(first && second){
            
            if(first->data <= second->data){
                tail->child = new Node(first->data);
                tail = tail->child;
                first=first->child;    
            }
            else{ 
                tail->child = new Node(second->data);
                tail = tail->child;
                second = second->child;
            }
        }
        else if(first){
            tail->child = new Node(first->data);
            tail = tail->child;
            first=first->child;  
        }
        else{
            tail->child = new Node(second->data);
            tail = tail->child;
            second = second->child;
        }
        
    }
    return finalList->child;
    
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
	if(!head ||!head->next )return head;

	head->next = flattenLinkedList(head->next);
	
	head = mergeTwoLists(head, head->next);
    
	return head;
}

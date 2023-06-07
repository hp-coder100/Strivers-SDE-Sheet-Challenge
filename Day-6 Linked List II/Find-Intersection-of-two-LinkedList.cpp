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


int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_map<Node*, int> mp;
    Node* first = firstHead;
    Node* second = secondHead;

    while(first || second){
        if(first){
            if(mp[first])return first->data;
            mp[first]++;
            first = first->next;
        }
        if(second){
            if(mp[second])return second->data;
            mp[second]++;
            second = second->next;
        }
    }
    return NULL;
}


int getDifference(Node* head1,Node* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}

//utility function to check presence of intersection
int findIntersection(Node* head1,Node* head2) {
 int diff = getDifference(head1,head2);
        if(diff < 0) 
            while(diff++ != 0) head2 = head2->next; 
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1->data;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1->data;


}
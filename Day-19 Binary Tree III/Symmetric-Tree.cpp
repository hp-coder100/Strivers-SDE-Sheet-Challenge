#include<bits/stdc++.h>
using namespace std;  
template <typename T>  
class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

bool symmetric(BinaryTreeNode<int> *a, BinaryTreeNode<int> *b){
    if(a == NULL && b==NULL)return true;
    
    if(a==NULL||b==NULL)return false;

    if(a->data != b->data)return false;

    return symmetric(a->left, b->right) && symmetric(a->right, b->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
        // Write your code here.
    if(!root)return true;        
    return symmetric(root->left, root->right);

}
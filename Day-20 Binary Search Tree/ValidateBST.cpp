#include <bits/stdc++.h> 
using namespace std;
template <typename T>
    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(!root)return true;
   
    if(root->left && root->left->data > root->data)return false;

    if(root->right && root->right->data < root->data)return false;
       

    return validateBST(root->left) && validateBST(root->right);


}
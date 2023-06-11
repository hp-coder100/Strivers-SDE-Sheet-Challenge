#include <bits/stdc++.h> 
using namespace std;

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };


bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(!root)return false;

    int val = root->data;
    if(val==x)return true;

    if(x > val)return searchInBST(root->right, x);

    else return searchInBST(root->left, x);

}
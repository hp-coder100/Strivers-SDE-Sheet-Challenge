#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };


//recursive;
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)return NULL;

    TreeNode<int>* next = root->right;
    flattenBinaryTree(next);
    root->right = root->left;
    flattenBinaryTree(root->right);
    TreeNode<int> *temp = root;
    while(temp->right!= NULL){
        temp = temp->right;
    }
    temp->right = next;
    return root;

}


//Morris

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int>* curr = root;

    while(curr!=NULL){

        if(curr->left){

        TreeNode<int>* pred = curr->left;

            while(pred->right){

                pred = pred->right;

            }

            pred->right=curr->right;

            curr->right=curr->left;

            curr->left=NULL;

    }

    curr=curr->right;

    }

    return root;
}
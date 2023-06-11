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
void inOrder(BinaryTreeNode<int> *root, vector<BinaryTreeNode<int>*> &inorder){
    if(!root)return;

    inOrder(root->left, inorder);
    inorder.push_back(root);
    inOrder(root->right, inorder);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here

    vector<BinaryTreeNode<int>*> inorder;
    inOrder(root, inorder);
    int n= inorder.size();
    for(int i=0;i<n;i++){
        if(i==0){
            inorder[i]->left = NULL;
        }
        else{
            inorder[i]->left = inorder[i-1];
        }
        if(i==n-1){
            inorder[i]->right = NULL;
        }
        else{
            inorder[i]->right = inorder[i+1];
        }
    }

    return inorder[0];
}
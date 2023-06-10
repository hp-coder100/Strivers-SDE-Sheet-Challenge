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

int height(BinaryTreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);

    return max(left_height,right_height) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.

    if(!root)return true;
    if(abs(height(root->left)-height(root->right)) > 1)return false;

    return isBalancedBT(root->left) && isBalancedBT(root->right);
}
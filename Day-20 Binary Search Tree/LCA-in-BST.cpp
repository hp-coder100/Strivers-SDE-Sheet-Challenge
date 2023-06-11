#include <bits/stdc++.h> 
using namespace std;
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(!root)return NULL;
    
    int data =  root->data;

    if(P->data < data && Q->data < data)
        return LCAinaBST(root->left, P, Q);
    

    if(P->data > data && Q->data > data)
        return LCAinaBST(root->right, P, Q);

    return root;
    

}

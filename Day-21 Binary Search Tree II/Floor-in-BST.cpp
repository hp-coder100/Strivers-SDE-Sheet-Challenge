#include<bits/stdc++.h> 
using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    TreeNode<int> *temp = root;
    int ans = root->val;
    while(temp){
        if(temp->val > X){
            temp =temp->left;
        }
        else{
            ans = temp->val;
            temp = temp->right;
        }
    }
    return ans;
}
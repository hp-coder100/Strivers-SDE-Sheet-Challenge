#include <bits/stdc++.h> 
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
TreeNode<int> *getNode(vector<int> &arr, int start, int end){

    if(start>end)return NULL;


    int mid = start +(end-start)/2;

    TreeNode<int> *root = new TreeNode<int>(arr[mid]);

    root->right = getNode(arr, mid+1, end);
    root->left = getNode(arr, start, mid-1);

    return root;
}


TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return getNode(arr, 0, n-1);
}
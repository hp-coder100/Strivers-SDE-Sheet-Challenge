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

void inOrder(TreeNode<int> *root, vector<int> &ans){
    if(!root)return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);

}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    if(!root) return -1;

    vector<int> ans;
    inOrder(root, ans);
    if(k>ans.size())return -1;
    return ans[k-1];
}

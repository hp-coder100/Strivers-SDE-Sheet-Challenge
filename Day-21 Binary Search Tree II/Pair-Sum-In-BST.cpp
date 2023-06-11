#include <bits/stdc++.h> 
using namespace std;
    template <typename T>

    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

void inOrder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(!root)return;

    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);

}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    
    vector<int> ans;
    inOrder(root, ans);

    int s = 0, e = ans.size()-1;


    while(s<e){
        
        int sum = ans[s]+ans[e];
        
        if(sum==k)return true;

        if(sum > k)e--;
        else s++;

        
    }
    return false;

}
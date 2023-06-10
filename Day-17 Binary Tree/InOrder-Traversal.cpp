
#include <bits/stdc++.h> 
using namespace std; 
class TreeNode{
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


void inOrder(TreeNode* root, vector<int> &ans){
    if(!root)return;
    
    inOrder(root->left, ans);
    
    ans.push_back(root->data);
    
    inOrder(root->right,ans);

}

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}
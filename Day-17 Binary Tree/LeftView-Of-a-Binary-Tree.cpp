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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    

    vector<int> ans;
    if(!root)return ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){

        int size = q.size();
        for(int i=0;i<size; i++){
            TreeNode<int> * node = q.front();
            q.pop();

            if(i==0)ans.push_back(node->data);

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    } 

    return ans;
}
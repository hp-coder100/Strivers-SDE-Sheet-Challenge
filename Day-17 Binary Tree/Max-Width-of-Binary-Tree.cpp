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

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(!root)return 0;
    
    int ans=1;

    queue<TreeNode<int>*> q;
    q.push(root);


    while(!q.empty()){

        int size = q.size();
        if(size>ans)ans = size;
        for(int i=0;i<size;i++){
            TreeNode<int>* node = q.front();
            
            q.pop();    
            
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);        
        }    

    }

    return ans;
    
}
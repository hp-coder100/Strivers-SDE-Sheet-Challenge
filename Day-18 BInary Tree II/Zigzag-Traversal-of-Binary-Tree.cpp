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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(!root)return ans;

    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    bool flag = true;
    while(!q.empty()){

        int size = q.size();
        vector<int> temp(size);
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* node = q.front();
            
            q.pop();    
            if(flag){
                temp[i] = node->data;
            }
            else{
                temp[size-i-1] = node->data;
            }
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);        
        }
        for(auto i:temp){
            ans.push_back(i);
        }
        flag = !flag;    

    }

    return ans;
}

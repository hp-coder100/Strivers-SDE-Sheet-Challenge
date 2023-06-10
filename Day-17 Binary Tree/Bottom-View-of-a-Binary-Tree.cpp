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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;

    if(!root)return ans;

    queue<pair<BinaryTreeNode<int>*,int>> q;
    q.push(make_pair(root,0));

    map<int, int> mp;
    mp[0] = root->data;

    while(!q.empty()){

        int size = q.size();
        for(int i=0;i<size;i++){
            BinaryTreeNode<int>* node = q.front().first;
            int hz = q.front().second;
            q.pop();    
            mp[hz] = node->data;

            if(node->left)q.push(make_pair(node->left, hz-1));
            if(node->right)q.push(make_pair(node->right, hz+1));        
        }    

    }

    for(auto it:mp)ans.push_back(it.second);
    return ans;
}

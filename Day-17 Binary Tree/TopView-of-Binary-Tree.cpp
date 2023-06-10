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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;

    if(!root)return ans;

    queue<pair<TreeNode<int>*,int>> q;
    q.push(make_pair(root,0));

    map<int, int> mp;
   

    while(!q.empty()){

        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode<int>* node = q.front().first;
            int hz = q.front().second;
            q.pop();    
            if(mp.find(hz)==mp.end())mp[hz] = node->val;

            if(node->left)q.push(make_pair(node->left, hz-1));
            if(node->right)q.push(make_pair(node->right, hz+1));        
        }    

    }

    for(auto it:mp)ans.push_back(it.second);
    return ans;
}
#include <bits/stdc++.h> 
using namespace std;    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
vector<int> ans;

    if(!root)return ans;

    queue<pair<TreeNode<int>*,int>> q;
    q.push(make_pair(root,0));

    map<int, vector<int>> mp;
   

    while(!q.empty()){

        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode<int>* node = q.front().first;
            int hz = q.front().second;
            q.pop();    
            mp[hz].push_back(node->data);

            if(node->left)q.push(make_pair(node->left, hz-1));
            if(node->right)q.push(make_pair(node->right, hz+1));        
        }    

    }



    for(auto it:mp)
        for(auto i:it.second)ans.push_back(i);
    return ans;


}
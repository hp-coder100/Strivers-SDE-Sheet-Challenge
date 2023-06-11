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

class BSTiterator
{

    vector<int> ele;
    int curr;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        inOrder(root, ele);
        curr = 0;
    }
    void inOrder(TreeNode<int> *root,vector<int> &ele){
        if(!root)return;
        
        inOrder(root->left, ele);
        ele.push_back(root->data);
        inOrder(root->right, ele);
    }

    int next()
    {
        // write your code here
        if(hasNext()){
            return ele[curr++];
        }
        return -1;
    }

    bool hasNext()
    {
        return curr < ele.size();
        // write your code here
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
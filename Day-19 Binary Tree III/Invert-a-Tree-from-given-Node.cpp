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


bool invert(TreeNode<int> *root,TreeNode<int> *parent, TreeNode<int> *leaf){
    if(!root) return false;

    if(root->data==leaf->data){
        leaf->left = parent;
        return true; 
    }

    if(invert(root->right, root, leaf)){
        root->right = NULL;
        if(root->left){
            TreeNode<int> *newNode = root->left;
            root->right = newNode;
        }
        root->left = parent;
        return true;
    }
    else if(invert(root->left, root, leaf)){
        root->left = parent;
        return true;
    }
    
    return false;
}

// void setParent(TreeNode<int> *root, TreeNode<int> *parent, unordered_map<TreeNode<int> *, TreeNode<int>*> &mp){
//     if(!root)return;
//     mp[root] = parent;
//     setParent(root->left, root, mp);
//     setParent(root->right, root, mp);
// }
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    //bool solve = invert(root, NULL, leaf);

    // unordered_map<TreeNode<int>*, TreeNode<int>*> mp;
    // setParent(root, NULL, mp);    
    // TreeNode<int> *temp = leaf;

    // while(temp){
        
    //     if(temp->left)
    //     {
    //         TreeNode<int> *newNode = temp->left;
    //         temp->right = newNode;
    //     }
    //     temp->left = mp[temp];
    //     temp = temp->left;
    // }
    
    bool solve = invert(root, NULL, leaf);

    
    return leaf;
}

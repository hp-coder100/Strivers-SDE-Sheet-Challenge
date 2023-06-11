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
TreeNode<int> *construct(vector<int> &inorder, vector<int> &preorder,
                   int preStart,int preEnd,int inStart,int inEnd, unordered_map<int, int> &mp){
    if(preStart > preEnd)return NULL;
    if(inStart > inEnd) return NULL;

    TreeNode<int> *node = new TreeNode<int>(preorder[preStart]);
    int ind = mp[preorder[preStart]];
    int ele = ind - inStart;
    
    node->right = construct(inorder, preorder, preStart+ele+1, preEnd, ind+1, inEnd, mp);
    node->left = construct(inorder, preorder, preStart+1, preStart+ele, inStart, ind-1, mp);

    return node;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    unordered_map<int, int> mp;
    
    int n = inorder.size();
    for(int i=0;i<n;i++){
        mp[inorder[i]] = i;
    }    
    return construct(inorder, preorder,0, n-1, 0, n-1, mp);
}
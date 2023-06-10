#include <bits/stdc++.h> 
using namespace std;
template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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

void solve(TreeNode<int>*root, int x, vector<int> curr, vector<int>&ans){
	if(!root)return;

	if(root->data==x){
		curr.push_back(x);
		ans = curr;
		return;
	}

	curr.push_back(root->data);
	solve(root->left, x, curr, ans);
	solve(root->right, x, curr, ans);


}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	vector<int> curr;
	solve(root, x, curr, ans);
	return ans;


}

//without extra vector

bool solve(TreeNode<int>*root, int x,  vector<int>&curr){
	if(!root)return false;

	curr.push_back(root->data);

	if(root->data==x){
		return true;
	}

	if(solve(root->left, x, curr) || solve(root->right, x, curr)){
		return true;
	}
	curr.pop_back();
	return false;


}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	
	vector<int> curr;
	bool res = solve(root, x, curr);
	return curr;


}
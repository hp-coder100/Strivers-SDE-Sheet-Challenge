#include <bits/stdc++.h> 
using namespace std;

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

graphNode* solve(graphNode* node, unordered_map<graphNode*, graphNode*> &mp){
	graphNode* newNode = new graphNode(node->data);
	mp[node] = newNode;

	for(auto it : node->neighbours){
		if(mp.find(it)!=mp.end()){
			newNode->neighbours.push_back(mp[it]);
		}
		else{
			newNode->neighbours.push_back(solve(it, mp));
		}

	}
	return newNode;
}


graphNode *cloneGraph(graphNode *node)
{
	unordered_map<graphNode*, graphNode*> mp;
	    // Write your code here.
	return solve(node, mp);

	
}
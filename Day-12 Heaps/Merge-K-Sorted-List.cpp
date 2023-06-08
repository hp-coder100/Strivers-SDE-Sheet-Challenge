#include <bits/stdc++.h> 
using namespace std;
class Node{
    public:
    int val, row, col;
    Node(int x, int y, int z){
        val = x;
        row = y;
        col = z;
    }
};
class Compare{
    public:
    bool operator()(Node* a, Node *b){
                return a->val > b->val;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for(int i=0;i<k;i++){
        Node* x= new Node(kArrays[i][0], i, 0);
        pq.push(x);
    }


    while(!pq.empty()){

        Node *top = pq.top();
        pq.pop();

        ans.push_back(top->val);

        if(top->col+1 < kArrays[top->row].size()){
            Node* y = new Node(kArrays[top->row][top->col+1], top->row, top->col+1);
            pq.push(y);
        }

    }
    return ans;

}

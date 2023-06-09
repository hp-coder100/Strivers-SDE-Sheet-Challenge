#include<bits/stdc++.h>
using namespace std;
struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
//brute force
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	
		//	Write your coode here.
		
		vector<int> ans;
		for(int i=0;i<queries.size();i++){
			int x = queries[i][0];
			int y = queries[i][1];
			int mn = 0;
			bool flag = true;
			for(int j=0;j<arr.size();j++){
				if(arr[j] <= y){
					mn = max(mn, arr[j]^x);
					flag = false;
				}
			}
			if(flag)ans.push_back(-1);
			else ans.push_back(mn);
		}
		return ans;


}

//using ties
vector < int > maxXorQueries(vector < int > & arr, vector < vector < int 
>> & queries) {
  vector < int > ans(queries.size(), 0);
  vector < pair < int, pair < int, int >>> offlineQueries;
  sort(arr.begin(), arr.end());
  int index = 0;
  for (auto & it: queries) {
    offlineQueries.push_back({
      it[1],
      {
        it[0],
        index++
      }
    });
  }
  sort(offlineQueries.begin(), offlineQueries.end());
  int i = 0;
  int n = arr.size();
  Trie trie;

  for (auto & it: offlineQueries) {
    while (i < n && arr[i] <= it.first) {
      trie.insert(arr[i]);
      i++;
    }
    if (i != 0) ans[it.second.second] = trie.findMax(it.second.first);
    else ans[it.second.second] = -1;
  }
  return ans;
}
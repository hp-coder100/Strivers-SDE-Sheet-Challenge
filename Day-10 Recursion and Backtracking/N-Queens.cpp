#include<bits/stdc++.h>
using namespace std;
bool checkIfSafe(int row,int col,int n, vector<int> &board){
      int duprow = row;
      int dupcol = col;

      while (row >= 0 && col >= 0) {
        if (board[row*n+col] == 1)
          return false;
        row--;
        col--;
      }

      col = dupcol;
      row = duprow;
      while (col >= 0) {
        if (board[row*n+col] == 1)
          return false;
        col--;
      }

      row = duprow;
      col = dupcol;
      while (row < n && col >= 0) {
        if (board[row*n+col] == 1)
          return false;
        row++;
        col--;
      }
      return true;
}



void solve(int  col, int n, vector<int> &board, vector<vector<int>> &ans){

    if(col==n){
        ans.push_back(board);
        return;
    }


    for(int i=0;i<n;i++){
        if(checkIfSafe(i, col, n, board)){
            board[(i*n) + col] =  1;
            solve(col+1, n, board, ans);
            board[(i*n) + col] = 0;  
        }
    }



}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> board(n*n, 0);
    solve(0, n, board, ans);
    return ans;
}
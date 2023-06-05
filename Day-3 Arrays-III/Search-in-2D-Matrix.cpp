#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(!matrix.size()) return false;
    int row = matrix.size();
    int col = matrix[0].size();
    int start = 0;
    int end = (row*col) -1;
    while(start <= end){

        int mid = start+(end-start)/2;
        int val = matrix[mid/col][mid%col];
        if(target==val)
            return true;

        if(val > target) end = mid-1;
        else start = mid+1;

    }
    return false;

        
}
#include<bits/stdc++.h>

void setZero(int row, int col, int n, int m, vector<vector<int>> &mat){
	for(int i=0;i<n;i++)if(mat[i][col]!=0) mat[i][col]= -1;
	for(int j=0;j<m;j++)if(mat[row][j]!=0) mat[row][j] = -1;
}
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n= matrix.size(), m = matrix[0].size();

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				setZero(i, j, n, m, matrix);
			};
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==-1){
				matrix[i][j] = 0;
			};
		}
	}
	
}
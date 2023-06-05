#include <bits/stdc++.h>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    if(n<=1 || m<=1)
    return;
    int startR =0, startC=0, endR =n-1, endC=m-1;

    while(startR<endR && startC<endC){

        int element = mat[startR][startC];
        int i=startR;
        while(i<=endC){
            int temp = mat[startR][i];
            mat[startR][i] = element;
            element = temp;
            i++;
        }
        i= startR+1;
        while(i<=endR){
            int temp = mat[i][endC];
            mat[i][endC] = element;
            element = temp;
            i++;
        }
        i=endC-1;
        while(i>=startC){
            int temp = mat[endR][i];
            mat[endR][i] = element;
            element = temp;
            i--;
        }
        i=endR-1;
        while(i>=startR){
            int temp = mat[i][startC];
            mat[i][startC]=element;
            element = temp;
            i--;
        }

        startC++;
        startR++;
        endC--;
        endR--;
        
    }
}
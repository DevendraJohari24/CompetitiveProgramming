/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

*/
#include<bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int row[m], col[n];
    for(int i=0;i<n;i++){
        col[i]=1;
    }
    for(int i=0;i<m;i++){
        row[i]=1;
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==0 || col[j]==0){
                matrix[i][j] = 0;
            }
        }
    }
}
// More Optimized Approach TC: O(m*n) SC: O(1)
/*
void setZeores(vector<vector<int>>& matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int col = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0 && j!=0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
            else if(matrix[i][j]==0 && j==0){
                col = 0;
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1;j<m;j++){
            if(matrix[0][j]==0 || matrix[i][0]==0){
                matrix[i][j] = 0;
            }
        }
    }
    // corner cases
    if(matrix[0][0]==0){
        for(int i=0; i<m; i++){
            matrix[0][i] = 0;
        }
    }
    if(col == 0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }
}


*/
int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    setZeroes(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0;j<matrix[0].size(); j++){
            cout<< matrix[i][j]<<" ";
        }
    }
    return 0;
}
/*
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

    Integers in each row are sorted in ascending from left to right.
    Integers in each column are sorted in ascending from top to bottom.

 

Example 1:

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

*/

#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int i=0, j=m-1;
    while(i!=n and j!=-1){
        if(matrix[i][j]> target){
            j--;
        }
        else if(matrix[i][j]<target){
            i++;
        }
        else{
            return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target = 5;
    cout<< searchMatrix(matrix, target);
    return 0;
}
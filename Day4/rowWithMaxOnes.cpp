/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).
*/

// Optimizing Approach = Binary Search TC: O(nlogn)-> looking for the first element to be the one

// Expected Optimization TC: O(n+m)
#include<bits/stdc++.h>
using namespace std;
int rowWithMaxOnes(vector<vector<int>>arr, int n, int m){
    int row = -1;
    int pos = m - 1;
    for(int i=0; i<m; i++){
        if(arr[0][i]){
            pos = i-1;
            row = 0;
            break;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=pos; j>-1; j--){
            if(arr[i][j]){
                row = i;
                pos = j-1; 
            }else{
                break;
            }
        }
    }
    return row;
}
int main(){
    int m = 4;
    int n = 4;
    vector<vector<int>> arr = {
        {0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1},{0, 0, 0, 0}
    };
    cout<<rowWithMaxOnes(arr, n, m);
    return 0;
}
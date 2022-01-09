/*
Problem Description

Given an array of integers A, sort the array into a wave like array and return it, In other words, arrange the elements into a sequence such that 

a1 >= a2 <= a3 >= a4 <= a5.....

NOTE : If there are multiple answers possible, return the one that's lexicographically smallest.



Problem Constraints

1 <= len(A) <= 106

1 <= A[i] <= 106


Input Format

First argument is an integer array A.


Output Format

Return an array arranged in the sequence as described.


Example Input

Input 1:

A = [1, 2, 3, 4]

Input 2:

A = [1, 2]



Example Output

Output 1:

[2, 1, 4, 3]

Output 2:

[2, 1]
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> wave(vector<int> &A) {
    int n = A.size();
    int temp;
    sort(A.begin(),A.end());
    for(int i = 0; i<=n-2 ;i++){
        if(i%2==0){
            if(A[i] < A[i+1]){
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                
            }
        }else{
            if(A[i] > A[i+1]){
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
            }
        }
    }
    return A;
}

int main(){
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = wave(A);
    for(int i=0;i<B.size(); i++){
        cout<< B[i]<<" ";
    }
    return 0;
     
}
































































































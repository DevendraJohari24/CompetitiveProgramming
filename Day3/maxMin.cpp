/*
Problem Description

Given an array A of size N. You need to find the sum of Maximum and Minimum element in the given array.

NOTE: You should make minimum number of comparisons.



Problem Constraints

1 <= N <= 105

-109 <= A[i] <= 109



Input Format

First and only argument is an integer array A of size N.


Output Format

Return an integer denoting the sum Maximum and Minimum element in the given array.


Example Input

Input 1:

 A = [-2, 1, -4, 5, 3]

Input 2:

 A = [1, 3, 4, 1]



Example Output

Output 1:

 1

Output 2:

 5

*/


#include<bits/stdc++.h>
using namespace std;

/*
// Divide and Conquer Approach
int solve(vector<int> &A){
    int n = A.size();
    for(int i =0; i<n/2; i++){
        if(A[i]>A[n-i-1]){
            swap(A[i], A[n-i-1]);
        }
    }
    int mx = A[0];
    int mn = A[0];
    for(int i=0;i<n/2; i++){
        mn = min(mn, A[i]);
    }
    for(int i=n/2;i<n; i++){
        mx = max(mx, A[i]);
    }
    return mx+mn;
}


*/
int maxMin(vector<int> &A) {
    int min_element=INT_MAX, max_element=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(A[i]>max_element){
            max_element = A[i];
        }
        if(A[i]<min_element){
            min_element = A[i];
        }
    }
    return max_element + min_element;
}

int main(){
    vector<int> A = {-2, 1, -4, 5, 3};
    cout<<maxMin(A);
    return 0;
}
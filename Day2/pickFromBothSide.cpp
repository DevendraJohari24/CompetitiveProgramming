/*

Problem Description

Given an integer array A of size N.

You can pick B elements from either left or right end of the array A to get maximum sum.

Find and return this maximum possible sum.

NOTE: Suppose B = 4 and array A contains 10 elements then

You can pick first four elements or can pick last four elements or can pick 1 from front and 3 from back etc . you need to return the maximum possible sum of elements you can pick.


Problem Constraints

1 <= N <= 105

1 <= B <= N

-103 <= A[i] <= 103



Input Format

First argument is an integer array A.

Second argument is an integer B.



Output Format

Return an integer denoting the maximum possible sum of elements you picked.


Example Input

Input 1:

 A = [5, -2, 3 , 1, 2]
 B = 3

Input 2:

 A = [1, 2]
 B = 1



Example Output

Output 1:

 8

Output 2:

 2

*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int pickFromBothSide(vector<int>& A, int B){
    int n = A.size();
    int sm = 0;
    for(int i = 0; i<B; i++){
        sm = sm + A[i];
    }
    int ans = sm;
    int point1 = n - 1;
    int point2 = B - 1;
    while(point2>=0){
        sm = sm + A[point1] - A[point2];
        ans = max(ans, sm);
        point2--;
        point1--;
    }
    return ans;
}
int main(){
    vector<int> A = {5, -2, 3, 1, 2};
    int B = 3;
    cout<<pickFromBothSide(A,B);
    return 0;
}
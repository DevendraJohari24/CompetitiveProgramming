/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.

*/
// Optimize Approach -> Understanding Mod Function
#include<bits/stdc++.h>
using namespace std;
int maximumAbsoluteDifference(vector<int>& A){
    int mx1 = INT_MIN, mx2 = INT_MIN, mn1 = INT_MAX, mn2 = INT_MAX;
    int n = A.size();
    int temp1 , temp2;
    for(int i=0; i<n; i++){
        temp1 = A[i] + i + 1;
        temp2 = A[i] - i - 1;
        mx1 = max(temp1, mx1);
        mn1 = min(temp1, mn1);
        mx2 = max(temp2, mx2);
        mn2 = min(temp2, mn2);
    }
    return max(mx1-mn1, mx2-mn2);

}
int main(){
    vector<int> A = {1, 3, -1};
    cout<<maximumAbsoluteDifference(A);
    return 0;
}
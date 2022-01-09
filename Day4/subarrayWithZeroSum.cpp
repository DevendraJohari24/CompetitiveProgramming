/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.

*/

// Optimized Approach -> Unordered Map

#include<bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n){
    unordered_map<int, int> ump;
    int sm = 0;
    ump[0] = 1;
    bool ans = false;
    for(int i =0; i<n; i++){
        sm = sm + arr[i];
        if(ump.find(sm)!=ump.end()){
            ans = true;
            break;
        }
        ump[sm] = 1;
    }
    return ans;
}
int main(){
    int n = 5;
    int arr[n] = {4, 2, -3, 1, 6};
    cout<<subArrayExists(arr,n);
    return 0;
}
/*
Given an array arr of n positive integers and a number k. One can apply a swap operation on the array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers less than or equal to k together, i.e. make them a contiguous subarray.

Example 1:

Input : 
arr[ ] = {2, 1, 5, 6, 3} 
K = 3
Output : 
1
Explanation:
To bring elements 2, 1, 3 together,
swap index 2 with 4 (0-based indexing),
i.e. element arr[2] = 5 with arr[4] = 3
such that final array will be- 
arr[] = {2, 1, 3, 6, 5}

*/
// Optimization Approach -> Sliding Window Approach
#include<bits/stdc++.h>
using namespace std;
int minSwapAndKTogether(vector<int>& arr, int k){
    int ans;
    int n = arr.size();
    int cnt = 0;
    int total = 0;
    for(int i=0; i<n; i++){
        if(arr[i]<=k){
            total++;
        }
    }
    for(int i=0;i<total;i++){
        if(arr[i]<=k){
            cnt++;
        }
    }
    ans = total-cnt;
    for(int i = total; i<n; i++){
        if(arr[i-total]<=k){
            cnt--;
        }
        if(arr[i]<=k){
            cnt++;
        }
        ans = min(ans, total-cnt);
    }
    return ans;
}
int main(){
    vector<int> arr = {2, 1, 5, 6, 3};
    int k = 3;
    cout<<minSwapAndKTogether(arr, k);
    return 0;
}
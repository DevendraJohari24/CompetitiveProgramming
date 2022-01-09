/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

*/

// Optimized Approach by checking all the elements to the copy sorted array
// Where first mismatch found = a and where last mismatch found = b our answer is b-a+1

// More Optimized Approach
#include<bits/stdc++.h>
using namespace std;
int shortestUnsortedSubarray(vector<int>& nums)
{
    int first=-1;
    int n = nums.size();
    int last = -1;
    for(int i=0; i<n-1; i++){
        if(nums[i]>nums[i+1]){
            first = i;
            break;
        }
    }
    for(int i=n-1; i>0; i--){
        if(nums[i]<nums[i-1]){
            last = i;
            break;
        }
    }
    if(first==-1){
        return 0;
    }
    int mx = nums[first];
    int mn = nums[last];
    for(int i=first; i<last;i++){
        mx = max(mx, nums[i]);
        mn = min(mn, nums[i]);
    }
    int start=0; int end = n-1;
    for(int i=first-1;i>-1;i++){
        if(nums[i]<= mn){
            start = i+1;
            break;
        }
    }
    for(int i=last+1;i<n;i++){
        if(nums[i]>mx){
            end = i-1;
            break;
        }
    }
    return end-start+1;
}
int main(){
    vector<int> nums = {2,6,4,8,10,9,15};
    cout<<shortestUnsortedSubarray(nums);
    return 0;
}
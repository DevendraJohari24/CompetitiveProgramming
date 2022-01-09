/*

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.


*/

// Kadane's Algorithm

#include<bits/stdc++.h>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums){
    int ans = nums[0];
    int prev_sum = 0;
    int curr_sum = 0;
    int n = nums.size();
    for(int i=0; i<n-1; i++){
        curr_sum = prev_sum + nums[i];
        ans = max(ans, curr_sum);
        prev_sum = max(0, curr_sum);
    }
    return ans;

}
int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<< maxSubArray(nums);

}
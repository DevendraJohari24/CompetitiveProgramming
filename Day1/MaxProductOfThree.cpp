/*
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6

*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;

int maximumProduct(vector<int>& nums){
    int n = nums.size();
    int mx[3] = {INT_MIN, INT_MIN, INT_MIN};
    int mn[2] = {INT_MAX, INT_MAX};
    int fir, sec;
    for(int i=0;i<n;i++){
        if(nums[i]>=mx[0]){
            fir = mx[0];
            sec = mx[1];
            mx[0] = nums[i];
            mx[1] = fir;
            mx[2] = sec;
        }
        else if(nums[i]>=mx[1]){
            fir = mx[1];
            mx[1] = nums[i];
            mx[2] = fir;
        }
        else if(nums[i] > mx[2]){
            mx[2] = nums[i];
        }

        if(nums[i]<=mn[0]){
            fir = mn[0];
            mn[0] = nums[i];
            mn[1] = fir;
        }
        else if(nums[i]<mn[1]){
            mn[1] = nums[i];
        }
    }
    return max(mn[0]*mn[1]*mx[0], mx[0]*mx[1]*mx[2]);
}


int main(){
    vector<int> nums = {1, 2, 3};
    cout<< maximumProduct(nums);
    return 0;
}
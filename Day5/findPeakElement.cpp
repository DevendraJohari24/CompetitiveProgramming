/*
A peak element is an element that is strictly greater than its neighbors.

Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

*/

#include<bits/stdc++.h>
using namespace std;
// Binary Search Approach
/*
int findPeakElement(vector<int>& nums){
    int n = nums.size();
    int high = n-1;
    int low = 0;
    int mid;
    if(n==0){
        return 0;
    }
    while(low<high){
        mid = (low + high) / 2;
        if(nums[mid] > nums[mid+1]){
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

*/

int findPeakElement(vector<int>& nums) {
    int max=0;
    int index=0;
    max= *max_element(nums.begin(), nums.end());
    for(int i;i<nums.size();i++){
        if(nums[i] == max){
            index = i;
            break;
        }
    }
    return index;
}
int main(){
    vector<int> nums = {1, 2, 3, 1};
    cout<< findPeakElement(nums);
    return 0;
}


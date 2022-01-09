/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3

*/

/*
Optimization Approach
1. Sorting TC: O(nlogn) SC: O(1)
2. Hashing TC: O(n) SC: O(n)
*/

/*
Most Optimization Approach TC: O(n) SC: O(1)
idea -> Maximum missing positive integer can be only n+1
which is the worst case for that otherwise it is in 1 to n
all the numbers less than 0 are useless to us.

*/

#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>& nums){
    int n = nums.size();
    int start = 0;
    for(int i=0; i<n; i++){
        if(nums[i]>n || nums[i]<=0){
            swap(nums[start], nums[i]);
            start++;
        }
    }
    int ind;
    for(int i=start; i<n; i++){
        ind = start + abs(nums[i])-1;
        if(ind>=n){
            continue;
        }
        nums[ind] = -1*abs(nums[ind]);
    }
    int ans = 1;
    for(int i=start;i<n;i++){
        if(nums[i]>0){
            break;
        }
        ans++;
    }
    return ans;
}

int main(){
    vector<int> nums = {1,2,0};
    cout<< firstMissingPositive(nums);
    return 0;
}

/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:

Input: nums = [1,1]
Output: [2]

*/

// Two Optimized Approach -> 1. Sorting TC: O(nlogn) SC: O(1) and 2. HashMap TC: O(n) SC: O(n)

// Most Optimized Approach -> Altering Array Apporach O(1)
// Altering the array means that try to store the information in the array in such a way that after analysing the array once again we will be able to find what elements are not stored in the array.

#include<bits/stdc++.h>
using namespace std;
vector<int> findDisappearNumbers(vector<int>& nums){
    vector<int> ans;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[abs(nums[i])-1]>0){
            nums[(abs(nums[i]))- 1] = -1 * nums[(abs(nums[i])) - 1];
        }
    }
    for(int i = 0; i<n; i++){
        if(nums[i]>0){
            ans.push_back(i+1);
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> ans = findDisappearNumbers(nums);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i] <<" ";
    }
    return 0;
}
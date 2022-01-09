/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

*/
// Optimized Approach
// Prefix and Suffix Product Array TC: O(n) SC: O(n) 
// More OPtimized Approach
#include<bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans;
    int temp=1;
    for(int i=0;i<nums.size();i++){
        ans.push_back(temp);
        temp = temp*nums[i];
    }
    temp = 1;
    for(int i=nums.size()-1;i>-1;i--){
        ans[i] = ans[i]*temp;
        temp = temp*nums[i];
    }
    return ans;
}
int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<int> ans = productExceptSelf(nums);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i]<<" ";
    }
    return 0;
}
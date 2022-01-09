/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
*/



#include<bits/stdc++.h>
using namespace std;
/*
// Discarding that part of array which is not same
int majorityElement(vector<int>& nums){
    int n = nums.size();
    int current = nums[0];
    int cnt = 1;
    for(int i=1; i<n; i++){
        if(cnt == 0){
            current = nums[i];
            cnt=1;
            continue;
        }
        if(current == nums[i]){
            cnt++;
        }else{
            cnt--;
        }
    }
    return current;
}
*/
int majorityElement(vector<int>& nums) {
    int maj_index=0, count=1;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==nums[maj_index]){
            count++;
        }else{
            count--;
        }
        if(count==0){
            maj_index = i;
            count = 1;
        }
    }
    return nums[maj_index];
}
int main(){
    vector<int> nums = {3, 2 ,3};
    cout<<majorityElement(nums);
    return 0;
}
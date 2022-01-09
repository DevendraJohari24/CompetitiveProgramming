/*
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

 

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

*/


#include<bits/stdc++.h>
int checkSubarraySum(vector<int>& nums, int k){
    unordered_map<int, int> ump;
    ump[0] = -1;
    int sm = 0;
    for(int i=0; i<nums.size(); i++){
        sm = (sm + nums[i])%k;
        if(ump.find(sm)!=ump.end()){
            if(i-ump[sm]>=2){
                return true;
            }
        }
        else{
            ump[sm] = i;
        }
    }
    return false;
}
using namespace std;
int main(){
    vector<int> nums = {23,2,4,6,7};
    int k = 6;
    cout<<checkSubarraySum(nums, k);
    return 0;
}

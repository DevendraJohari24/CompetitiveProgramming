/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

*/

// Hashing -> Storing a value in the key value pairs we use unordered map that store the value of two data types
#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, int> store;
    int n = nums.size();
    int req;
    for(int i=0;i<n;i++){
        req = target - nums[i];
        if(store.find(req) != store.end()){ // check if req is inside in store if not it store[nums[i]] =i
            ans.push_back(store[req]);
            ans.push_back(i);
            break;
        }
        store[nums[i]]=i;
    }
    return ans;
}
int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> ans = twoSum(nums, target);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i]<< " ";
    }
    return 0;
}
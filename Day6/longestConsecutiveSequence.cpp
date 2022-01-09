/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/

// Optimized Solution --> Hashing

#include<bits/stdc++.h>
using namespace std;
int longestConsecutiveSequence(vector<int>& nums){
    int n = nums.size();
    int ans = 1;
    if(!n){
        return 0;
    }
    unordered_map<int, int> ump;
    for(int i=0; i<n; i++){
        ump[nums[i]] = 1;
    }
    for(int i=0; i<n; i++){
        if(ump.find(nums[i]-1)==ump.end()){ //
            int curr = nums[i];
            int ln = 0;
            while(ump.find(curr) != ump.end()){
                curr++;
                ln++;
            }
            ans = max(ans, ln);
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {100,4,200,1,3,2};
    cout<<longestConsecutiveSequence(nums);
    return 0;
}

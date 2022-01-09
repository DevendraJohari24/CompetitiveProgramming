/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.

 

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

*/

// Optimized Approach --> Counting approach

#include<bits/stdc++.h>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums){
    int ans = 0;
    int cnt = 0;
    for(int i=0; i< nums.size(); i++){
        if(nums[i]){
            cnt++;
        }
        else{
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    return ans;
}
int main(){
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout<<findMaxConsecutiveOnes(nums);
    return 0;
}
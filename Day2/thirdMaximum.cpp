/*
Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

 

Example 1:

Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

*/

// Approach -> Optimization Keep track of max 3
// Corner cases -> int_min = 2 ^-31  if there are only 2 distinct number it should return maximum instead of int_min
#include<bits/stdc++.h>
using namespace std;
int thirdMax(vector<int>& nums) {
    int n = nums.size();
    int fir, sec;
    int max[3] = {INT_MIN, INT_MIN, INT_MIN};
    int cnt=0;
    bool flag=1;
    for(int i=0;i<n;i++){
        if(nums[i]==max[0] || nums[i] == max[1] || nums[i] == max[2]){
            if(nums[i]==INT_MIN && flag){
                flag = 0;
                cnt++;
            }
            continue; // start the loop all over again
        }
        if(nums[i]>max[0]){
            cnt++;
            fir = max[0];
            sec = max[1];
            max[0] = nums[i];
            max[1] = fir;
            max[2] = sec;
        }
        else if(nums[i]>max[1]){
            cnt++;
            fir = max[1];
            max[1] = nums[i];
            max[2] = fir;
        }
        else if(nums[i]>max[2]){
            cnt++;
            max[2] = nums[i];
        }
    }
    if(cnt<=2){
        return max[0];
    }else{
        return max[2];
    }
        
}
int main(){
    vector<int> nums = {3, 2, 5};
    cout<< thirdMax(nums);
    return 0;
}
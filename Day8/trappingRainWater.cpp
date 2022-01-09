/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/
// Optimization Approach -> Two Pointer Approach
#include<bits/stdc++.h>
using namespace std;
int trappingRainWater(vector<int>& height){
    int n = height.size();
    int l=0, r=n-1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while(l<=r){
        left_max = max(left_max, height[l]);
        right_max = max(right_max, height[r]);
        if(left_max<=right_max){
            ans = ans - height[l] + left_max;
            l++;
        }
        else{
            ans = ans-height[r] + right_max;
            r--;
        }
    }
    return ans;
}
int main(){
    vector<int> height = {4,2,0,3,2,5};
    cout<<trappingRainWater(height);
    return 0;    
}

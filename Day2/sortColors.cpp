/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

*/

#include<bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
        int first=0;
        int last = nums.size()-1;
        int index = 0;
        while(index<=last){
            switch(nums[index]){
                case 0:
                    swap(nums[first++],nums[index++]);
                    break;
                case 1:
                    index++;
                    break;
                case 2:
                    swap(nums[last--],nums[index]);
                    break;
            }
        }
    }
int main(){
    vector<int> colors = {2, 0, 2, 1, 1, 0};
    sortColors(colors);
    for(int i =0; i<colors.size();i++){
        cout<<colors[i];
    }
    return 0;
}
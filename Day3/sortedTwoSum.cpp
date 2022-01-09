/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> output;
    int n = numbers.size();
    int l =0 , h = n-1;
    while(l<h){
        if(numbers[l] + numbers[h] == target){
            output.push_back(l+1);
            output.push_back(h+1);
            break;
        }
        else{
            if((numbers[l] + numbers[h])>target) {
                h--;
            }
            else{
                l++;
            }
        }
    }
    return output;
}

int main(){
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> output = twoSum(numbers, target);
    for(int i=0; i<output.size(); i++){
        cout<< output[i]<< " ";
    }
    return 0;
}
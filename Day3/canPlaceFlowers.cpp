/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

*/

#include<bits/stdc++.h>
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int count=0;
    int len = flowerbed.size();
    // corner case
    if(len==1){
        if(flowerbed[0]+n<=1){
            return true;
        }
        return false;
    }
    for(int i=0;i<len;i++){
        if(flowerbed[i]){
            continue;
        }
        if(i==0 && flowerbed[i+1]==0){
            count++;
            flowerbed[i]=1;
        }else if(i==len-1 && flowerbed[i-1]==0){
            count++;
            flowerbed[i]=1;
        }
        else{
            if(i==0 or i==len-1){
                continue;
            }
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                count++;
                flowerbed[i]=1;
            }
        }
        
        
    }
    
    if(count>=n){
        return true;
    }else{
        return false;
    }
}
int main(){
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    cout<<canPlaceFlowers(flowerbed, n);
    return 0;

}
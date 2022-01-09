/*
Problem Description
You're given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example:

Input: [1 2 3 1 1]
Output: 1 
1 occurs 3 times which is more than 5/3 times.

*/
// Optimization : Sorting TC: O(nlogn) SC: O(1)  Hashing TC: O(n) SC: O(n)

// More Optimization--> Discarding Majority Element ... Idea -> If we remove 3 different element from the array . Any element which is greater that n/3 still remains so.


#include<bits/stdc++.h>
using namespace std;
int nDIvide3RepeatNumber(const vector<int>& A){
    int first=0, second=0, cnt1=0, cnt2=0, n = A.size();
    for(int i=0; i<n; i++){
        if(A[i]==first){
            cnt1++;
        }
        else if(A[i]==second){
            cnt2++;
        }
        else if(cnt1==0){
            first = A[i];
            cnt1++;
        }
        else if(cnt2==0){
            second = A[i];
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i=0;i<n; i++){
        if(A[i]==first){
            cnt1++;
        }else if(A[i]==second){
            cnt2++;
        }
    }
    if(cnt1>n/3){
        return first;
    }
    else if(cnt2>n/3){
        return second;
    }
    else{
        return -1;
    }
}
int main(){

}
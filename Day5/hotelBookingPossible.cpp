/*
Problem Description

A hotel manager has to process N advance bookings of rooms for the next season. His hotel has C rooms. Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .


Input Format

First argument is an integer array A containing arrival time of booking.

Second argument is an integer array B containing departure time of booking.

Third argument is an integer C denoting the count of rooms.


Output Format

Return True if there are enough rooms for N bookings else return False.

Return 0/1 for C programs.


Example Input

Input 1:

 A = [1, 3, 5]
 B = [2, 6, 8]
 C = 1



Example Output

Output 1:

 0
 
*/



#include<bits/stdc++.h>
using namespace std;
bool hotelBookingPossible(vector<int> &arrive, vector<int> &depart , int K){
    int n= arrive.size();
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int ar = 0;
    int cur = 0;
    int de = 0;
    bool ans = true;
    while(ar<n){
        if(arrive[ar]<depart[de]){
            ar++;
            cur++;
        }
        else if(depart[de]<arrive[ar]){
            de++;
            cur--;
        }
        else{
            de++;
            ar++;
        }
        if(cur>K){
            ans = false;
            break;
        }
    }
    return ans;
}
int main(){
    vector<int> arrive = {1, 3, 5};
    vector<int> depart = {2, 6, 8};
    int C = 1;
    bool result = hotelBookingPossible(arrive, depart, C);
    cout<< result;
    return 0;
}
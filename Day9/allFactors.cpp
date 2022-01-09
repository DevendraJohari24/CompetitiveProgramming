/*
Given a number N, find all factors of N.

Example:

N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.

Problem Approach:

Complete code in the hint.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> allFactors(int A){
    vector<int> ans;
    int i=1;
    while(i*i<=A){
        if(A%i==0){
            int second=A/i;
            if(second==i){
                ans.push_back(i);
            }
            else{
                ans.push_back(i);
                ans.push_back(second);
            }

        }
        i++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main(){
    int N=6;
    vector<int> ans = allFactors(N);
    for(int i =0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
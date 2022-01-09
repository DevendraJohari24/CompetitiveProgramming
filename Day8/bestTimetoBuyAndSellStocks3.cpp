/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
*/

#include<bits/stdc++.h>
using namespace std;
int bestbuyAndSellStocksThree(vector<int>& prices){
    int n = prices.size();
    int profit[n];
    int mx = prices[n-1];
    profit[n-1]=0;
    for(int i=n-2;i>-1;i--){
        mx = max(mx, prices[i]);
        profit[i] = max(profit[i+1], mx-prices[i]);
    }
    int mn = prices[0];
    for(int i=1;i<n;i++){
        mn = min(mn, prices[i]);
        profit[i] = max(profit[i-1], profit[i]+prices[i]-mn);
    }
    return profit[n-1];
}

int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout<<bestbuyAndSellStocksThree(prices);
    return 0;
}
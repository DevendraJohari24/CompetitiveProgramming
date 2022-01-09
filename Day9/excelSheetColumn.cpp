/*
Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
*/

#include<bits/stdc++.h>
using namespace std;
int titleToNumber(string columnTitle){
    int def = 'A' - 1;
    int n = columnTitle.length();
    int temp;
    int cur=1;
    int ans=0;
    for(int i=n-1;i>-1;i--){
        temp = columnTitle[i];
        ans = ans + (temp-def)*cur;
        if(i!=0){
            cur = cur*26;
        }
    }
    return ans;
}
int main(){
    string columnTitle = "ZY";
    cout<<titleToNumber(columnTitle);
    return 0;
}
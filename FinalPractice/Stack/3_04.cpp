#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &s, int x){
    // Base case
    if(s.empty()){
        s.push(x);
        return;
    }
    
    // 1 case me solve remaining recursion will handle
    if(!s.empty() && x > s.top()){
        s.push(x);
        return;
    }
    
    int topEle = s.top();
    s.pop();
    // recursion
    sortedInsert(s, x);
    // backtrack
    s.push(topEle);
}
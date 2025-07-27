#include <iostream>
#include <stack>

using namespace std;

void sortedInsert(stack<int> &s,int val){
    // Base cases
    if(s.empty()){
        s.push(val);
        return;
    }
    if(!s.empty() && s.top() < val){
        s.push(val);
        return;
    }

    // 1 case me
    int topEle = s.top();
    s.pop();
    // Recursion
    sortedInsert(s,val);
    // Backtrack
    s.push(topEle);
}
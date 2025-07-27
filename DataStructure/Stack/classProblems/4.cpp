#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int topEle = s.top();
    s.pop();
    // Recursion
    insertAtBottom(s,val);
    // Backtracking
    s.push(topEle);
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    // 1 case me solve
    int topEle = s.top();
    s.pop();
    // Recursion
    reverseStack(s);
    // Backtrack ->insert at bottom the topEle
    insertAtBottom(s,topEle);
}


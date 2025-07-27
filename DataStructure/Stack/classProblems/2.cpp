#include <iostream>
#include <stack>

using namespace std;

void solve(stack<int>& myStack, int x){
    // Base case
    if(myStack.empty()){
        myStack.push(x);
        return;
    }

    // 1 case me solve remaining recursion will handle
    int topEle = myStack.top();
    myStack.pop();
    solve(myStack,x);
    // Backtrack
    myStack.push(topEle);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack,x);
    return myStack;
}

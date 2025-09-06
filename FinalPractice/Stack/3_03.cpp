#include <bits/stdc++.h>
using namespace std;


bool isSortedHelper(stack<int>& s, int prev) {
    // Base case: empty stack means sorted
    if(s.empty()) {
        return true;
    }

    // 1 case me solve remaining recursion
    int curr = s.top();
    s.pop();

    // If current is greater than prev → not sorted
    if(curr > prev) {
        s.push(curr); // backtrack before returning
        return false;
    }

    bool result = isSortedHelper(s, curr);

    // Backtrack
    s.push(curr);

    return result;
}

bool isSorted(stack<int>& s) {
    return isSortedHelper(s, INT_MAX);
}

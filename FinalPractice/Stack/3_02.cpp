#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(stack<int> &s, int x){
        // base case
        if(s.empty()){
            s.push(x);
            return;
        }
        
        // 1 case me solve remaining recursion will handle
        int top = s.top();
        s.pop();

        solve(s, x);

        // backtrack
        s.push(top);
    }
  
    stack<int> insertAtBottom(stack<int> st, int x) {
        solve(st, x);
        return st;
    }
};
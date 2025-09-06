#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void insertAtBottom(stack<int> &s, int x){
        // base case
        if(s.empty()){
            s.push(x);
            return;
        }
        
        // 1 case me solve remaining recursion will handle
        int top = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(top);
    }
    
    void reverseAStack(stack<int> &s){
        // base case
        if(s.empty()){
            return;
        }
        
        // 1 case me solve remaining recursion will handle
        int top = s.top();
        s.pop();
        // Recursion
        reverseAStack(s);
        // !Backtrack -> insertAtBottom
        insertAtBottom(s, top);
    }
  
    void reverse(stack<int> &St) {
        // code here
        reverseAStack(St);
        return;
    }
};
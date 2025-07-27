#include <iostream>
#include <stack>
#include <cmath>

using namespace std;


class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(stack<int> &s,int size,int count){
        // Base case
        if((size&1) == 0 && count == floor((size+1)/2)+1){
            s.pop();
            return;
        }
        if((size&1) == 1 && count == floor((size+1)/2)){
            s.pop();
            return;
        }
        
        int topEle = s.top();
        s.pop();
        solve(s,size,count+1);
        s.push(topEle);
    }
    void deleteMid(stack<int>& s, int sizeOfStack) {
        int count = 1;
        solve(s,sizeOfStack,count);
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
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

        void sortStack(stack<int> &s){
            // base case
            if(s.empty())
                return;
            
            // 1 case
            int topEle = s.top();
            s.pop();
            // recursion
            sortStack(s);
            // !Backtrack => SORTED_INSERT
            sortedInsert(s, topEle);
        }

        void sort(stack<int> &s){
            sortStack(s);
        }
};
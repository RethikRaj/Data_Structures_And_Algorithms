#include <bits/stdc++.h>
using namespace std;

// Solution 1 : TC: O(1) , SC : O(2*N)
class MinStack {
public:
    // *pair<value, minTillNow>
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(make_pair(val, val));
        }else{
            s.push(make_pair(val, min(val, s.top().second )));
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

// Solution 2 : TC: O(1), SC : O(N + 1)
class MinStack2 {
public:
    stack<long long> s;   // store as long long
    long long minEle;

    MinStack2() {
        minEle = LLONG_MAX;
    }
    
    void push(int val) {
        if(s.empty()) {
            minEle = val;
            s.push(val);
        } else {
            if(val >= minEle) {
                s.push(val);
            } else {
                // long long encodedVal = 2LL * val - minEle;
                long long encodedVal = 2 * (long long )val - minEle;
                s.push(encodedVal);
                minEle = val;
            }
        }
    }
    
    void pop() {
        if(s.empty()) {
            return;
        }

        long long topVal = s.top();
        if(topVal < minEle) {
            minEle = 2*minEle - topVal;
        }

        s.pop();        
    }
    
    int top() {
        if(s.empty()){
            return -1;
        } 

        long long topVal = s.top();
        if(topVal < minEle) {
            return (int)minEle;
        }
        return (int)topVal;
    }
    
    int getMin() {
        if(s.empty()) {
            return -1;
        }
        return (int)minEle;
    }
};




/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
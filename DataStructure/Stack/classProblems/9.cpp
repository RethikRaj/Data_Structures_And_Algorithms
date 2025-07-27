#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// this works when all elements are +ve
vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> s;
    // this below step you will forget =>DONT FORGET
    s.push(-1); // The NSE of rightmost element is -1

    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        // while top element of the stack >= curr , it cant be NSE of the curr element or any element to its left => It is useless => pop()
        while(!s.empty() && s.top() >= curr){
            s.pop();
        }
        // NSE of arr[i] is at top of the stack
        ans[i] = s.top();
        // Since the curr element may be NSE of the elements to its left => push it into stack
        s.push(arr[i]); 
    }
    return ans;
}

// this works even if there are -ve elements in array
// made by me
// i/p :[10,6,8,7,-1,1,-3] => o/p : [6,-1,INT_MIN,INT_MIN,-3,-3,INT_MIN]
vector<int> nextSmallerElementFINAL(vector<int> &arr, int n){
    vector<int> ans(n);
    stack<int> s;
    // this below step you will forget =>DONT FORGET
    s.push(INT_MIN); // The NSE of rightmost element is (INT_MIN)

    for(int i=n-1;i>=0;i--){
        int curr = arr[i];
        // while top element of the stack >= curr , it cant be NSE of the curr element or any element to its left => It is useless => pop()
        while(!s.empty() && s.top() >= curr){
            s.pop();
        }
        // NSE of arr[i] is at top of the stack => store ans
        ans[i] = s.top();
        
        // Since the curr element may be NSE of the elements to its left => push it into stack
        s.push(arr[i]); 
    }
    return ans;
}



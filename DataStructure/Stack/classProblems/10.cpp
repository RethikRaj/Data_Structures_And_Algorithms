#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    vector<int> ans;
    stack<int> s;
    s.push(-1);
    
    for(int i=0;i<A.size();i++){
        int curr = A[i];
        while(!s.empty() && s.top() >= curr){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(curr);
    }
    return ans;
}

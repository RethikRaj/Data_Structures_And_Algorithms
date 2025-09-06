#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> s;
        vector<int> ans(n , -1);
        
        s.push(-1);
        for(int i = n - 1;i >= 0;i--){
            
            // pop the elements in stack till we get an element which is strictly smaller than arr[i];
            while(!s.empty() && arr[i] <= s.top()){
                s.pop();
            }
            
            // arr[i] > s.top()
            ans[i] = s.top();
            s.push(arr[i]);
        }
        
        return ans;
    }
};
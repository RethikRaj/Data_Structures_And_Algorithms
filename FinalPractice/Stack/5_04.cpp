#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> prevGreaterElement(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> ans(n);
        stack<int> s;
        s.push(INT_MAX);
        for(int i = 0 ;i < n ; i++){
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }
            
            // arr[i] < s.top()
            if(s.top() == INT_MAX){
                ans[i] = -1;
            }else{
                ans[i] = s.top();
            }
            
            s.push(arr[i]);
        }
        
        return ans;
    }
};
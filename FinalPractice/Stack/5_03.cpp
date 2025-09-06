#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> prevSmallerEle(vector<int>& arr) {
        int n = arr.size();
        
        stack<int> s;
        vector<int> ans(n , -1);
        
        s.push(-1);
        for(int i=0; i < n; i++){
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
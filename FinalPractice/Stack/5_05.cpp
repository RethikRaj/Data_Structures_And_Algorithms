#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getIndexOfNextSmallerElement(vector<int>& arr, vector<int> &ans){
        int n = arr.size();
        stack<int> s;
        // !Stack stores index -> If no NSE for an element we need n as the index of NSE for that element , therefore push n
        s.push(n);
        for(int i = n - 1; i >= 0; i--){
            // Ensure not empty and also valid index 
            while(!s.empty() && s.top() < n && arr[i] <= arr[s.top()]){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
    }

    void getIndexOfPreviousSmallerElement(vector<int>& arr, vector<int> &ans){
        int n = arr.size();
        // !Stack stores index -> If no PSE for an element we need -1 as the index of PSE for that element , therefore push -1
        stack<int> s;
        s.push(-1);
        for(int i = 0; i < n; i++){
            // Ensure not empty and also valid index
            while(!s.empty() && s.top() >= 0 && arr[i] <= arr[s.top()]){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> indexOfNSE(n);
        getIndexOfNextSmallerElement(heights, indexOfNSE);

        vector<int> indexOfPSE(n);
        getIndexOfPreviousSmallerElement(heights, indexOfPSE);

        int maxArea = INT_MIN;

        for(int i = 0;i < n;i++){
            int currWidth = indexOfNSE[i] - indexOfPSE[i] - 1 ;
            int currHeight = heights[i];
            int currArea = currWidth * currHeight;
            maxArea = max(currArea, maxArea);
        }
        return maxArea;

    }
};
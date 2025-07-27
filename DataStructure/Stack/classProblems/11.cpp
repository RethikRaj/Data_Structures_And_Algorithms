#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    //finds the indexes of NSE(next smaller element) for each element
    void findNSEIndexes(vector<int> &heights,vector<int> &NSEIndexes){
        int n = heights.size();
        stack<int> s;
        // DONT FORGET
        s.push(n); // why pushed n ? Because if for some element there is no NSE , then for width calculation , n is correct option
        for(int i=heights.size()-1;i>=0;i--){
            int curr = heights[i];
            while(!s.empty() && s.top() != n && heights[s.top()] >= curr){
                s.pop();
            }
            NSEIndexes[i] = s.top();
            s.push(i);
        }
    }

    //finds the indexes of PSE(previous smaller element) for each element
    void findPSEIndexes(vector<int> &heights,vector<int> &PSEIndexes){
        stack<int> s;
        // DONT FORGET
        s.push(-1); // why pushed -1 ? Because if for some element there is no PSE , then for width calculation , -1 is correct option
        for(int i=0;i<heights.size();i++){
            int curr = heights[i];
            while(!s.empty() && s.top() != -1 && heights[s.top()] >= curr){
                s.pop();
            }
            PSEIndexes[i] = s.top();
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // calculate NSE of all elements
        vector<int> NSEIndexes(n);
        findNSEIndexes(heights,NSEIndexes);

        // calculate PSE of all elements
        vector<int> PSEIndexes(n);
        findPSEIndexes(heights,PSEIndexes);

        //find max Area
        int maxArea = INT_MIN;
        for(int i=0;i<heights.size();i++){
            int width = NSEIndexes[i]-PSEIndexes[i]-1;
            int height = heights[i];
            int area = width*height;
            maxArea = max(maxArea,area);
        }
        return maxArea;
    }
};
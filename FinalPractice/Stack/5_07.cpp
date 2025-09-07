#include <bits/stdc++.h>
using namespace std;

// Solution 1 : 
// TC : O(n), SC : O(n)
class Solution {
public:
    void getLeftMax(vector<int> &arr, vector<int> &ans){
        int maxi = -1;
        for(int i=0;i < arr.size(); i++){
            maxi = max(maxi, arr[i]);
            ans[i] = maxi;
        }
    }

    void getRightMax(vector<int> &arr, vector<int> &ans){
        int maxi = -1;
        for(int i = arr.size() - 1;i >= 0; i--){
            maxi = max(maxi, arr[i]);
            ans[i] = maxi;
        }
    }

    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMaxes(n);
        getLeftMax(height, leftMaxes);

        vector<int> rightMaxes(n);
        getRightMax(height, rightMaxes);

        int trappedWater = 0;
        for(int i=0; i < n; i++){
            int heightOfWaterAboveCurrBar = min(leftMaxes[i], rightMaxes[i]) - height[i];
            // heightOfWaterAboveCurrBar >= 0
            trappedWater += heightOfWaterAboveCurrBar;
        }

        return trappedWater;

    }
};


// Solution 2 :
// TC; O(n), SC : O(1)



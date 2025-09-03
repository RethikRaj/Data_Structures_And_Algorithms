//  Leetcode 34 : Find First and Last Position of Element in Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getIndexOfLowerBound(vector<int> &arr, int target){
        // Corner Cases
        if(target < arr[0]){
            return 0;
        }

        if(target > arr[arr.size() - 1]){
            return arr.size();
        }

        int low = 0;
        int high = arr.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] < target){
                low = mid + 1; // discard left
            }else {
                ans = mid; // store
                high = mid - 1; // discard right
            }
        }
        return ans;
    }

    int getIndexOfUpperBound(vector<int> &arr, int target){
        // Corner Cases
        if(target < arr[0]){
            return 0;
        }

        if(target > arr[arr.size() - 1]){
            return arr.size();
        }

        int low = 0;
        int high = arr.size() - 1;
        int ans = arr.size();

        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] <= target){
                low = mid + 1; // discard left
            }else {
                ans = mid; // store
                high = mid - 1; // discard right
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // ! Approach : 
        // !Case 1 : Target is present in nums
        // First occurence of target : indexOfLowerBound of target
        // Last occurence og target : (indexOfUpperBound of target - 1)

        // !Case 2 : Target is not present in nums
        // How to find target is not present in nums -> if the element at lowerBound is not target then the target is missing or the index of lower bound is arr.size()
        vector<int> ans;
        if(nums.size() == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        
        int indexOfLowerBound = getIndexOfLowerBound(nums, target);
        if(indexOfLowerBound == nums.size() || nums[indexOfLowerBound] != target){
            // target is missing
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }

        int indexOfUpperBound = getIndexOfUpperBound(nums, target);
        ans.push_back(indexOfLowerBound);
        ans.push_back(indexOfUpperBound-1);
        return ans;

    }
};
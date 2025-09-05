// Search in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == target){
                return mid;
            }

            // *check if mid lies in upper curve or lower curve

            if(arr[mid] >= arr[low]){ // Mid lies in upper curve
                if(arr[low] <= target && target < arr[mid]){
                    // target belongs to left sorted part
                    high = mid - 1;
                }else{
                    // target belongs to right which is a sorted and rotated array
                    low = mid + 1;
                }
            }else{ // mid lies in lower curve
                if(arr[mid] < target && target <= arr[high]){
                    // target belongs to right which is a sorted part
                    low = mid + 1;
                }else{
                    // target belongs to left which is a sorted and rotated array
                    high = mid - 1;
                }
            }
        } 
        return -1;
    }
};



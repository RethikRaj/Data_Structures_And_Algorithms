// Find Minimum in Rotated Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high){
            
            // Step 1 : Check if it is a sorted search space
            if(arr[low] <= arr[high]){
                return arr[low];
            }

            int mid = low + (high - low)/2;

            // Check arr[mid] lies in upper curve or lower curve
            if(arr[mid] >= arr[low]){
                // arr[mid] lies in upper curve => discard left and move right
                low = mid + 1;
            }else{
                // arr[mid] lies in lower curve => discard right and move left

                // Check if arr[mid] is the answer
                if(mid - 1 >= 0 && arr[mid - 1] > arr[mid]){
                    return arr[mid];
                }

                high = mid - 1;
            }
        }
        return -1;
    }
};

// Same solution but different way of coding
class Solution2 {
public:
    int findMin(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high){
            
            // *Step 1 : Check if it is a sorted search space
            if(arr[low] <= arr[high]){
                return arr[low];
            }

            int mid = low + (high - low)/2;

            // *Step 2 : Check if arr[mid] is the answer
            if(mid - 1 >= 0 && arr[mid - 1] > arr[mid]){
                return arr[mid];
            }

            // *Step 3 : Check arr[mid] lies in upper curve or lower curve
            if(arr[mid] >= arr[low]){
                // arr[mid] lies in upper curve => discard left and move right
                low = mid + 1;
            }else{
                // arr[mid] lies in lower curve => discard right and move left
                high = mid - 1;
            }
        }
        return -1;
    }
};
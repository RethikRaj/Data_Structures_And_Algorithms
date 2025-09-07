#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();

        // Corner Case
        if(n == 1){
            return 0;
        }

        int low = 0;
        int high = n - 1;

        while(low <= high){
            int mid = low + (high - low)/2;

            // Check whether arr[mid] is peak
            // peak is first element
            if(mid == 0 && arr[mid] > arr[mid + 1]){
                return mid;
            }
            // peak is last element
            if(mid == n - 1 && arr[mid - 1] < arr[mid]){
                return mid;
            }
            // peak is in between
            if(mid-1 >= 0 && mid+1 < n && arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }


            // if arr[mid] is not peak check whether it lies in increasing or decreasing curve
            if( mid+1 < n && arr[mid] < arr[mid + 1]){
                // discard left
                low = mid + 1;
            }else{
                // discard right
                high = mid - 1;
            }
        }

        return -1;
    }
};
// Lower bound of target => First element >= target
// The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the given number

#include <bits/stdc++.h>
using namespace std;

int indexOfLowerBound(vector<int> &arr, int target){
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
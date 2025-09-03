// Upper bound of target => first element > target
// The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.

#include <bits/stdc++.h>
using namespace std;

int indexOfUpperBound(vector<int> &arr, int target){
    // Corner Cases
    if(target < arr[0]){
        return 0;
    }
    
    // *We dont need this 2nd corner case as i have initialised ans with arr.size()
    if(target > arr[arr.size() - 1]){
        return arr.size();
    }

    int low = 0;
    int high = arr.size() - 1;
    int ans = arr.size(); // *Why initialised to arr.size() -> Analyse this test case arr=[1] , target = 1

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
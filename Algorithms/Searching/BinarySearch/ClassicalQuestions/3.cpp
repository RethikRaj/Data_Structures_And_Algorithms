#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    while(start <= end){
        if(arr[mid] == target){
            return mid;
        }
        else if(target < arr[mid]){
            end = mid-1;
        }
        else if(target > arr[mid]){
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    return mid;
}
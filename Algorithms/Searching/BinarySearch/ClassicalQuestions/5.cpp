#include <iostream>
#include <vector>

using namespace std;

// Method 1 : Line A and Line B
int peakIndexInMountainArray(vector<int>& arr){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;

    while(start < end){
        if(arr[mid] < arr[mid+1]){
            // move right since peak will be in right
            start = mid+1;
        }
        else{
            // peak will be in left or at this position itsel => e = mid not e =mid-1;
            end = mid;
        }

        // Update mid
        mid = start + (end-start)/2;
    }

    return mid;
}

// Method 2 :
int peakIndexInMountainArray(vector<int>& arr) {
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end-start)/2;
    while(start <= end){
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){ // arr[mid] peak element
            return mid;
        }else if(arr[mid] < arr[mid+1]){ // arr[mid] belongs to part A => increasing order =>peak will be in right =>move right
            start = mid+1;
        }else if(arr[mid] > arr[mid+1]){ // arr[mid] belongs to part B => decreasing order =>peak will be in left =>move left
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

// Method 3 : Store and compute

int peakIndexInMountainArray(vector<int>& arr) {
    int s = 0;
    int e = arr.size();
    int mid = s+(e-s)/2;
    int peakIndex = -1;

    while(s <= e){
        if(mid+1 < arr.size() && arr[mid] < arr[mid+1]){
            s = mid+1;
        }else{
            peakIndex = mid;
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return peakIndex;
}



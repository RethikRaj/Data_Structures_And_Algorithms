#include <iostream>
#include <vector>
using namespace std;

int getPairFirstElementIndex(vector<int>& arr,int mid){
    if(arr[mid] == arr[mid-1]){
        return mid-1;
    }
    if(arr[mid] == arr[mid+1]){
        return mid;
    }
    return -1;
}


int findOddOccuringElement(vector<int>& arr){
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s+(e-s)/2;
    
    while(s<=e){
        // Single element
        if(s == e){
            return arr[mid];
        }
        int leftValue = -1;
        int rightValue = -1;
        int currValue = arr[mid];
        if(mid-1 >= 0){
            leftValue = arr[mid-1];
        }
        if(mid + 1 < n){
            rightValue = arr[mid+1];
        }
        
        // No duplicate or not in pair element
        if(leftValue != currValue && rightValue != currValue){
            return currValue;
        }
        // else mid may belong to left part or right part 
        // How to find ? => I need pair's first Element Index
        int pairFirstElementIndex = getPairFirstElementIndex(arr,mid);
        if(pairFirstElementIndex & 1 ){
            // pairFirstElementIndex is odd => I am in right part => move left
            e = mid-1;
        }else{
            // pairFirstElementIndex is even => I am in left part =>move right
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}
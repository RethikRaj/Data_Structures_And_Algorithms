#include <iostream>
#include <vector>

using namespace std;

// Finds the smallest(first) index having element >= target.
int lowerBound(vector<int>& arr,int target){
    int start = 0;
    int end = arr.size() - 1;
    int mid = (start) + (end-start)/2;
    int ansIndex = arr.size(); // question demanded that if not found then return size.
    while(start <= end){
        if(arr[mid] >= target){
            ansIndex = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        // Update
        mid = start + (end-start)/2;
    }
    return ansIndex;
}



int upperBound(vector<int>& arr,int target){

}
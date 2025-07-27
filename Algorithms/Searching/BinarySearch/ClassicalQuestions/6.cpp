#include <iostream>
#include <vector>

using namespace std;

int getPivotIndex(vector<int>& nums){
    int start = 0;
    int n = nums.size();
    int end = n-1;
    int mid = start + (end-start)/2;
    
    while(start <= end){
        if(start == end){
            // single element or in case of no rotation
            return start;
        }
        // answer found case
        if(mid+1 < n && nums[mid] > nums[mid+1]){
            return mid;
        }
        if(nums[mid] < nums[start]){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int binarySearch(vector<int>& nums,int target,int s,int e){
    int mid = s+(e-s)/2;

    while(s <= e){
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            s = mid+1;
        }else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivotIndex = getPivotIndex(nums);
    // cout << "Pivot Index is " << pivotIndex;
    int n = nums.size();

    int ans = -1;
    if(target >= nums[0] && target <= nums[pivotIndex]){
        ans = binarySearch(nums,target,0,pivotIndex);
    }else{
        ans = binarySearch(nums,target,pivotIndex+1,n-1);
    }

    return ans;
}
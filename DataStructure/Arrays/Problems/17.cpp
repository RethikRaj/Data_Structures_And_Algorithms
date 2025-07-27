#include <iostream>
#include <vector>
using namespace std;


// brute Force : 
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        int leftSum = 0;
        for(int j=0;j<i;j++){
            leftSum += nums[j];
        }
        int rightSum = 0;
        for(int j=i+1;j<n;j++){
            rightSum += nums[j];
        }

        if(leftSum == rightSum){
            return i;
        }
    }
    return -1;
}

// Pointer and totalSum
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for(int i=0;i<n;i++){
        totalSum += nums[i];
    }

    int leftSum = 0;
    int rightSum = totalSum - nums[0];
    int index = 0;
    while(index < n){
        if(leftSum != rightSum){
            leftSum += nums[index];
            index++;
            if(index < n)
                rightSum -= nums[index];
        }else{
            return index;
        }
    }
    return -1;
}

// Pointer and totalSum =>Implementation2
int pivotIndex(vector<int> arr) {
    int n = arr.size();
    // Calculate total sum
    int totalSum = 0;
    for(int i=0;i<n;i++){
        totalSum += arr[i];
    }

    int leftSum = 0;
    
    for(int i=0;i<n;i++){
        int rightSum = totalSum-leftSum-arr[i];
        if(leftSum == rightSum){
            return i;
        }
        // Update leftSum
        leftSum += arr[i];
    }
    return -1;
}



// second largest

#include <bits/stdc++.h>
using namespace std;

int findSecondLargest(vector<int> &nums){
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for(int i=0;i<nums.size();i++){
        if(nums[i] > largest){
            secondLargest = largest;
            largest = nums[i];
        }else if(nums[i] > secondLargest && nums[i] != largest){
            secondLargest = nums[i];
        }
    }
    return secondLargest;
}
// find 2nd smallest

#include <bits/stdc++.h>
using namespace std;

int findSecondSmallest(vector<int> &nums){
    int firstSmallest = INT_MAX;
    int secondSmallest = INT_MAX;
    for(int i=0;i<nums.size();i++){
        if(nums[i] < firstSmallest){
            secondSmallest = firstSmallest;
            firstSmallest = nums[i];
        }else if(nums[i] < secondSmallest && nums[i] != firstSmallest){
            secondSmallest = nums[i];
        }
    }
    return secondSmallest;
}
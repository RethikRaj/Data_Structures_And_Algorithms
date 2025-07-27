#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int index = 0;
    int count = 0; // counts consecutive ones
    int maxCount = INT_MIN;
    while(index < nums.size()){
        if(nums[index] == 1){
            count++;
        }else{
            maxCount = max(maxCount,count);
            count = 0;
        }
        index++;
    }
    maxCount = max(maxCount,count);
    return maxCount;
}


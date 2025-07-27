#include <iostream>
#include <vector>

using namespace std;

// method 2 : Kadane Algo (TC:O(N) , SC:O(1))
int kadaneAlgo(vector<int>& nums) {
    int maxSubArraySum = INT_MIN;
    int sum = 0;
    for(int i=0;i<nums.size();i++){
        // add to  sum
        sum += nums[i];
        // update maxSubArraySum
        maxSubArraySum = max(maxSubArraySum,sum);
        // check if sum < 0 , if yes then update sum = 0
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSubArraySum;
}

// Method 1 : Brute Force
int maxSubArray(vector<int>& nums) {
    int maxSubArraySum = INT_MIN;
    for(int start=0;start < nums.size();start++){
        int sum = 0;
        for(int end = start;end<nums.size();end++){
            sum += (nums[end]);
            maxSubArraySum = max(maxSubArraySum,sum);
        }
    }
    return maxSubArraySum;


    // Worst of worst
    // int maxSubArraySum = INT_MIN;
    // for(int start=0;start < nums.size();start++){
    //     for(int end = start;end<nums.size();end++){
    //         // subarray is from [start to end];
    //         int sum = 0;
    //         for(int k=start;k<=end;k++){
    //             sum += nums[k];
    //         }
    //         maxSubArraySum = max(maxSubArraySum,sum);
    //     }
    // }
    // return maxSubArraySum;
}


int main(){
    return 0;
}
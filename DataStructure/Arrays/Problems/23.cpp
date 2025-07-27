#include <iostream>
#include <vector>

using namespace std;




class Solution {
public:
    // Method 2: thinking like kadane's algo 
    double tryingLikeKadanes(vector<int>& nums, int &k) {
        int maxSum = INT_MIN;
        int sum = 0;
        int j = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(i>=k-1){ // i== k-1 => first subarray of length k 
                maxSum = max(maxSum,sum);
                sum = sum-nums[j];
                j++;
            }
        }
        return (double)maxSum / k;
    }


    // Method 1 : Sliding window concept  ( TC : O(n+k))
    double slidingWindow(vector<int>& nums, int &k){
        int maxSum = INT_MIN;
        
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        maxSum = max(maxSum,sum);

        int index = k;
        int i= 0;
        while(index < nums.size()){
            sum = sum-nums[i]+nums[index];
            maxSum = max(maxSum,sum);
            i++;
            index++;
        }

        return (double)(maxSum)/k;
    }

    double findMaxAverage(vector<int>& nums, int k) {
        //return slidingWindow(nums,k);
        return tryingLikeKadanes(nums,k);
    }
};

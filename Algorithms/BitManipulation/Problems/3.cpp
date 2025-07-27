#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int optimisedApproach(vector<int> &nums){
        int maxNumber = INT_MIN; // -> maxNumber is itself maximum bitwise value
        // int maxBitWiseAndValue = nums[0];
        int maxLength = INT_MIN;

        int index = 0;
        while(index < nums.size()){
            if(nums[index] >= maxNumber){
                // finding length of contigous maxNumber
                int start = index;
                while(index+1 < nums.size() && nums[index+1] == nums[index]){
                    index++;
                }
                int end = index;
                if(nums[index] > maxNumber){
                    // must update maxLength and maxNumber
                    maxNumber = nums[index];
                    maxLength = end-start+1;
                }
                else if(nums[index] == maxNumber){
                    // no need to update maxNumber
                    // check and update maxLength
                    maxLength = max(maxLength,end-start+1);
                }
                index++;
            }
            else{
                // nums[index] < maxNumber
                index++;
            }
        }
        return maxLength;
    }

    int bruteForce(vector<int> &nums){
        int maxLength = INT_MIN;
        int maxValue = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            int currValue = nums[i];
            for(int j=i;j < nums.size();j++){
                currValue = currValue & nums[j];
                if(currValue > maxValue){
                    maxValue = currValue;
                    maxLength = j-i+1;
                }else if(currValue == maxValue){
                    maxLength = max(maxLength,j-i+1);
                }
            }
        }

        return maxLength;
    }

    int longestSubarray(vector<int>& nums) {
        // return bruteForce(nums);

        return optimisedApproach(nums);
    }
};